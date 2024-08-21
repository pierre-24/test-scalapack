/* Inspired by https://wwwuser.gwdguser.de/~ohaan/ScaLAPACK_examples/demo_PDSYEV.f
 * Compute the eigenvalues and eigenvectors of a NxN real symmetric matrix `A`,
 * and check if they match by comparing with `|A * x_i - e_i * x_i|`, where `e_i` is the eigenvalue associated with `x_i`.
 *
 * Where:
 *
 * - `N = floor(sqrt(P)) * BLK_SIZE * BLK_PER_PROC`,
 *
 *    where `P` is the number of processors, `BLK_SIZE` is the block size and `BLK_PER_PROC` is the number of bloc per proc (> 1).
 *
 * - `A[i,j] = 1/(1+.5*fabs(i-j))`.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Int LA_INT
#ifdef USE_LA_MKL
#include <mkl.h>
#include <mkl_pblas.h>
#include <mkl_scalapack.h>
#define LA_INT MKL_INT
#else
#define LA_INT LA_INT
#endif
#include "cblacs.h"

#define BLK_SIZE 32
#define BLK_PER_PROC 2

LA_INT I_ZERO = 0, I_ONE = 1, I_M_ONE = -1, I_TWO = 2;
double D_ONE = 1.0, D_ZERO = 0.0, D_M_ONE = -1.0;

extern LA_INT indxl2g_(LA_INT* INDXGLOB, LA_INT* NB, LA_INT* IPROC, LA_INT* ISRCPROC, LA_INT* NPROCS);

int main(int argc, char* argv[]) {
    // constant
    LA_INT N, blk_size = BLK_SIZE, lwork;
    // global
    LA_INT nprocs, ctx_sys, glob_nrows, glob_ncols, glob_i, glob_j;
    // local
    LA_INT  iam, loc_row, loc_col, loc_nrows, loc_ncols, loc_lld, info;

    LA_INT desc_A[9], desc_r[9];
    double *A, *Ap, *X, *w, *r, *work;
    double norm_res, norm_A, norm_X;

    // initialize BLACS & system context
    Cblacs_pinfo(&iam, &nprocs);
    Cblacs_get(0, 0, &ctx_sys);

    // create the grid
    glob_nrows = (LA_INT) sqrt((double) nprocs);
    glob_ncols = nprocs / glob_nrows;
    N = glob_nrows * BLK_SIZE * BLK_PER_PROC;

    Cblacs_gridinit(&ctx_sys, "R", glob_nrows, glob_ncols);
    Cblacs_gridinfo(ctx_sys, &glob_nrows, &glob_ncols, &loc_row, &loc_col);

    if(iam == 0)
        printf("%d :: grid is %dx%d, matrix is %dx%d\n", iam, glob_nrows, glob_ncols, N, N);

    if(loc_row >= 0) { // if I'm in grid
        // compute length and create arrays
        loc_nrows = numroc_(&N, &blk_size, &loc_row, &I_ZERO, &glob_nrows);
        loc_ncols = numroc_(&N, &blk_size, &loc_col, &I_ZERO, &glob_ncols);
        loc_lld =  loc_nrows;

        A = calloc(loc_nrows * loc_ncols, sizeof(double));
        Ap = calloc(loc_nrows * loc_ncols, sizeof(double));
        X = calloc(loc_nrows * loc_ncols, sizeof(double));
        w = calloc(N, sizeof(double )); // it seems that all (!) eigenvalues are locally available
        r = calloc(loc_nrows, sizeof(double));

        if(A == NULL ||X == NULL || w == NULL) {
            printf("%d :: cannot allocate :(\n", iam);
            exit(EXIT_FAILURE);
        } else {
            printf("%d :: local matrix is %dx%d\n", iam, loc_nrows, loc_ncols);
        }

        // fill array locally
        for(LA_INT loc_j=1; loc_j <= loc_ncols; loc_j++) { /* FORTRAN STARTS AT ONE !!!!!!!!! */
            // translate local j to global j
            // see https://netlib.org/scalapack/explore-html/d4/deb/indxl2g_8f_source.html
            glob_j = indxl2g_(&loc_j, &blk_size, &loc_col, &I_ZERO, &glob_ncols) - 1;
            for(LA_INT loc_i=1; loc_i <= loc_nrows; loc_i++) {
                glob_i = indxl2g_(&loc_i, &blk_size, &loc_row, &I_ZERO, &glob_nrows) - 1;

                // set A[i,j]
                A[(loc_j - 1) * loc_nrows + (loc_i - 1)] = 1. / (1. + .5 * fabs(glob_i - glob_j));
                Ap[(loc_j - 1) * loc_nrows + (loc_i - 1)] = A[(loc_j - 1) * loc_nrows + (loc_i - 1)];
            }
        }

        // create descriptor for A, X, and r
        descinit_(desc_A, &N, &N, &blk_size, &blk_size, &I_ZERO, &I_ZERO, &ctx_sys, &loc_lld, &info);
        descinit_(desc_r, &N, &I_ONE, &blk_size, &blk_size, &I_ZERO, &I_ZERO, &ctx_sys, &loc_lld, &info);

        // request lwork
        // the (convoluted) formula is at https://www.ibm.com/docs/en/pessl/5.3.0?topic=easva-pdsyev-pzheev-all-eigenvalues-optionally-eigenvectors-real-symmetric-complex-hermitian-matrix
        double tmpw;
        pdsyev_("V", "U", &N, Ap, &I_ONE, &I_ONE, desc_A, w, X, &I_ONE, &I_ONE, desc_A, &tmpw, &I_M_ONE, &info);
        lwork = (LA_INT) tmpw;

        // compute the eigenvalues and vectors
        // NOTE: like dsyev(), the content of A is irremediably destroyed in the process :(
        work = calloc(lwork, sizeof(double ));
        pdsyev_("V", "U", &N, Ap, &I_ONE, &I_ONE, desc_A, w, X, &I_ONE, &I_ONE, desc_A, work, &lwork, &info);

        if(info != 0) {
            printf("%d :: error: info is %d\n", iam, info);
            exit(EXIT_FAILURE);
        }

        // compute norm of A
        norm_A = pdlange_( "I", &N, &N, A, &I_ONE, &I_ONE, desc_A, work);

        for(LA_INT i = 1; i <= N; i++) { // FORTRAN, starts at one
            // compute `r = A * x_i`
            // according to the doc of pdsyev, eigenvectors are located in columns
            pdgemv_("N", &N, &N,
                    &D_ONE, A, &I_ONE, &I_ONE, desc_A,
                    X, &I_ONE, &i, desc_A, &I_ONE,
                    &D_ZERO, r, &I_ONE, &I_ONE, desc_r, &I_ONE
            );

            // compute `r = r - e_i * x_i`
            double me_ = -w[i - 1];
            pdaxpy_(&N,
                    &me_, X, &I_ONE, &i, desc_A, &I_ONE,
                    r, &I_ONE, &I_ONE, desc_r, &I_ONE
                    );

            // compute norm of x_i and r
            norm_X = pdlange_( "1", &N, &i, X, &I_ONE, &I_ONE, desc_A, work);
            norm_res = pdlange_( "1", &N, &I_ONE, r, &I_ONE, &I_ONE, desc_r, work);
            double eps = pdlamch_(&ctx_sys, "e");
            double residual = norm_res / (2 * norm_A * norm_X * eps); // might not be the correct residual :(

            if(iam == 0)
                printf("%d :: eigenvalue #%d is %f, residual is %e\n", iam, i, w[i - 1], residual);
        }

        // free
        free(A);
        free(X);
        free(w);
        free(r);
        free(work);
    } else
        printf("%d :: i'm out!\n", iam);

    // finalize BLACS
    Cblacs_exit(0);
    return EXIT_SUCCESS;
}

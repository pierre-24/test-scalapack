/* Inspired by https://github.com/cjf00000/tests/blob/master/mkl/pblas3_d_example.c.
 *
 * Compute product of two NxN matrices, `C = A * B`,
 * and then check the residual `r = |B - inv(A) * C|`, where `inv(A)` is the inverse of `A`.
 *
 * In practice,
 *
 * - `N = floor(sqrt(P)) * BLK_SIZE * BLK_PER_PROC`, where `P` is the number of processors, `BLK_SIZE` is the block size and `BLK_PER_PROC` is the number of bloc per bloc (> 1).
 *
 * - `A` is an orthonormal matrix (similar to a Householder transformation) defined by:
 *
 *   `A[i,j] = (N-i-1 == j ? 1:0) - 2 * (N-i-1) * j / M`, where `M = N * (N-1) * (2 * N - 1) / 6`.
 *
 *   Therefore `inv(A) = tr(A)`, where `tr(A)` is the transpose of `A`.
 *
 * - `B` is a random matrix.
 *
 * Thus, the residual becomes `r = |B - tr(A) * C|`.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

#define BLK_SIZE 2
#define BLK_PER_PROC 2

LA_INT I_ZERO = 0, I_ONE = 1;
double D_ONE = 1.0, D_ZERO = 0.0;

extern LA_INT indxl2g_(LA_INT* INDXGLOB, LA_INT* NB, LA_INT* IPROC, LA_INT* ISRCPROC, LA_INT* NPROCS);

int main(int argc, char* argv[]) {
    // constant
    LA_INT N, blk_size = BLK_SIZE, M;
    // global
    LA_INT nprocs, ctx_sys, ctx_0, glob_nrows, glob_ncols, glob_i, glob_j;
    // local
    LA_INT  iam, loc_row, loc_col, loc_nrows, loc_ncols, loc_lld, info;

    LA_INT desc_A[9], desc_B[9], desc_C[9], desc_glob_dest_A[9];
    double *A, *B, *C;
    double *glob_dest_A = NULL;

    // initialize BLACS & system context
    Cblacs_pinfo(&iam, &nprocs);
    Cblacs_get(0, 0, &ctx_sys);

    // create the grid
    glob_nrows = (LA_INT) sqrt((double) nprocs);
    glob_ncols = nprocs / glob_nrows;
    N = glob_nrows * BLK_SIZE * BLK_PER_PROC;
    M = N * (N-1) * (2 * N - 1) / 6;

    Cblacs_gridinit(&ctx_sys, "R", glob_nrows, glob_ncols);
    Cblacs_gridinfo(ctx_sys, &glob_nrows, &glob_ncols, &loc_row, &loc_col);
    Cblacs_gridinit(&ctx_0, "R", 1, 1);

    if(iam == 0)
        printf("%d :: grid is %dx%d, matrix is %dx%d, M is %d\n", iam, glob_nrows, glob_ncols, N, N, M);

    if(loc_row >= 0) { // if I'm in grid
    	// compute length and create arrays
    	loc_nrows = numroc_(&N, &blk_size, &loc_row, &I_ZERO, &glob_nrows);
        loc_ncols = numroc_(&N, &blk_size, &loc_col, &I_ZERO, &glob_ncols);
        loc_lld =  loc_nrows;
    	A = calloc(loc_nrows * loc_ncols, sizeof(double));
    	B = calloc(loc_nrows * loc_ncols, sizeof(double));
    	C = calloc(loc_nrows * loc_ncols, sizeof(double));

    	if(A == NULL || B == NULL || C == NULL) {
    		printf("%d :: cannot allocate :(\n", iam);
    		exit(EXIT_FAILURE);
    	}

    	// fill arrays locally
    	for(LA_INT loc_i=1; loc_i <= loc_nrows; loc_i++) { /* FORTRAN STARTS AT ONE !!!!!!!!! */
            // translate local i to global i
            // see https://netlib.org/scalapack/explore-html/d4/deb/indxl2g_8f_source.html
            glob_i = indxl2g_(&loc_i, &blk_size, &loc_col, &I_ZERO, &glob_ncols) - 1;
    		for(LA_INT loc_j=1; loc_j <= loc_ncols; loc_j++) {
                glob_j = indxl2g_(&loc_j, &blk_size, &loc_row, &I_ZERO, &glob_nrows) - 1;
                A[(loc_i - 1) * loc_lld + (loc_j-1)] = (glob_i == glob_j ? 1.0:0.0) - (double) (2 * glob_i * glob_j) / ((double) M);
    		}
    	}

    	// create descriptor for A, B and C
    	descinit_(desc_A, &N, &N, &blk_size, &blk_size, &I_ZERO, &I_ZERO, &ctx_sys, &loc_lld, &info);
    	descinit_(desc_B, &N, &N, &blk_size, &blk_size, &I_ZERO, &I_ZERO, &ctx_sys, &loc_lld, &info);
    	descinit_(desc_C, &N, &N, &blk_size, &blk_size, &I_ZERO, &I_ZERO, &ctx_sys, &loc_lld, &info);

        pdgemm_("N", "C", &N, &N, &N, &D_ONE,
                A, &I_ONE, &I_ONE, desc_A,
                A, &I_ONE, &I_ONE, desc_A, &D_ZERO,
                B, &I_ONE, &I_ONE, desc_B
        );

        desc_glob_dest_A[1] = -1;

        if(iam == 0) {
            glob_dest_A = calloc(N * N, sizeof(double ));
            descinit_(desc_glob_dest_A, &N, &N, &N, &N, &I_ZERO, &I_ZERO, &ctx_0, &N, &info);
        }

        pdgemr2d(&N, &N, B, &I_ONE, &I_ONE, desc_B, glob_dest_A, &I_ONE, &I_ONE, desc_glob_dest_A, &ctx_sys);

        if(iam == 0) { // received all parts of the matrix

            printf("---\n");
            for(LA_INT i=0; i < N; i++) {
                for (LA_INT j = 0; j < N; ++j) {
                    printf("% .4f ", glob_dest_A[i * N + j]);
                }
                printf("\n");
            }

            free(glob_dest_A);
        }

    	// free
    	free(A);
    	free(B);
    	free(C);
    }

    // finalize BLACS
    Cblacs_exit(0);
    return EXIT_SUCCESS;
}

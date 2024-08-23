#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <mkl_blacs.h>
#include <mkl_scalapack.h>

#define BLK_SIZE 2
#define A_NCOLS 8
#define A_NROWS 12

MKL_INT I_ZERO = 0, I_ONE = 1;
double D_ONE = 1.0, D_ZERO = 0.0, D_M_ONE = -1.0;

extern MKL_INT indxl2g_(MKL_INT* INDXGLOB, MKL_INT* NB, MKL_INT* IPROC, MKL_INT* ISRCPROC, MKL_INT* NPROCS);

int main(int argc, char* argv[]) {
    // constant
    MKL_INT A_ncols = A_NCOLS, A_nrows = A_NROWS, blk_size = BLK_SIZE;
    // global
    MKL_INT nprocs, ctx_sys, ctx_all, ctx_0, glob_nrows, glob_ncols, glob_i, glob_j;
    // local
    MKL_INT  iam, loc_row, loc_col, loc_nrows, loc_ncols, loc_lld, info;

    MKL_INT desc_A[9], desc_dest[9];
    MKL_INT *loc_A;
    MKL_INT *glob_dest = NULL;

    // initialize BLACS & system context
    blacs_pinfo(&iam, &nprocs);
    blacs_get(&I_ZERO, &I_ZERO, &ctx_sys);

    // create the grid
    glob_nrows = (MKL_INT) sqrt((double) nprocs);
    glob_ncols = nprocs / glob_nrows;

    // NOTE: to use multiple grid, ctx_sys should not directly be set.
    ctx_all = ctx_sys;
    blacs_gridinit(&ctx_all, "R", &glob_nrows, &glob_ncols);
    blacs_gridinfo(&ctx_all, &glob_nrows, &glob_ncols, &loc_row, &loc_col);

    ctx_0 = ctx_sys;
    MKL_INT i0 = 1, j0 = 1;
    blacs_gridinit(&ctx_0, "R", &i0, &j0);

    if(iam == 0)
        printf("%d :: grid is %dx%d\n", iam, glob_nrows, glob_ncols);

    if(loc_row >= 0) { // if I'm in grid
        // compute length and create arrays
        loc_nrows = numroc_(&A_nrows, &blk_size, &loc_row, &I_ZERO, &glob_nrows);
        loc_ncols = numroc_(&A_ncols, &blk_size, &loc_col, &I_ZERO, &glob_ncols);
        loc_lld =  loc_nrows;
        loc_A = calloc(loc_nrows * loc_ncols, sizeof(MKL_INT));

        if(loc_A == NULL) {
            printf("%d :: cannot allocate :(\n", iam);
            exit(EXIT_FAILURE);
        } else {
            printf("%d :: local matrix is %dx%d\n", iam, loc_nrows, loc_ncols);
        }

        // fill arrays locally
        // Note: here, `A[i,j]`, where `i` is the index of the row and `j` the one of the column.
        // Since fortran is column major, `i` is the one changing the fastest
        for(MKL_INT loc_j=1; loc_j <= loc_ncols; loc_j++) { /* FORTRAN STARTS AT ONE !!!!!!!!! */
            // translate local j to global j
            // see https://netlib.org/scalapack/explore-html/d4/deb/indxl2g_8f_source.html
            glob_j = indxl2g_(&loc_j, &blk_size, &loc_col, &I_ZERO, &glob_ncols) - 1;
            for(MKL_INT loc_i=1; loc_i <= loc_nrows; loc_i++) {
                glob_i = indxl2g_(&loc_i, &blk_size, &loc_row, &I_ZERO, &glob_nrows) - 1;

                // set A[i,j]
                loc_A[(loc_j - 1) * loc_nrows + (loc_i - 1)] = glob_j * A_nrows + glob_i;
            }
        }

        // create descriptor for A
        descinit_(desc_A, &A_nrows, &A_ncols, &blk_size, &blk_size, &I_ZERO, &I_ZERO, &ctx_all, &loc_lld, &info);

        // send A to process #0, for the fun of it
        desc_dest[1] = -1;

        if(iam == 0) {
            glob_dest = calloc(A_nrows * A_ncols, sizeof(MKL_INT));
            descinit_(desc_dest, &A_nrows, &A_ncols, &A_nrows, &A_ncols, &I_ZERO, &I_ZERO, &ctx_0, &A_nrows, &info);
        }

        pigemr2d(&A_nrows, &A_ncols, loc_A, &I_ONE, &I_ONE, desc_A, glob_dest, &I_ONE, &I_ONE, desc_dest, &ctx_all);

        if(iam == 0) { // received all parts of the matrix, just for the fun of it

            // print the actual matrix, in column major form
            for (MKL_INT i = 0; i < A_nrows; ++i) {
                for(MKL_INT j=0; j < A_ncols; j++) {
                    printf("%03d ", glob_dest[j * A_nrows + i]);
                }
                printf("\n");
            }
        }

        // free
        free(loc_A);
    } else
        printf("%d :: i'm out!\n", iam);

    // finalize BLACS
    blacs_exit(&I_ZERO);
    return EXIT_SUCCESS;
}

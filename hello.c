/* This is a (adapted) translation of https://netlib.org/blacs/BLACS/Examples.html#HELLO.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LA_INT Int
#ifdef USE_LA_MKL
#include <mkl.h>
#define Int MKL_INT
#else
#define Int int
#endif
#include "cblacs.h"

int main(int argc, char* argv[]) {
    LA_INT iam, nprocs, ctx_sys, nrows, ncols, myrow, mycol, icaller, itscol, itsrow;

    // initialize BLACS
    Cblacs_pinfo(&iam, &nprocs);

    // create a rectangular grid
    nrows = (LA_INT) sqrt((double) nprocs);
    ncols = nprocs / nrows;
    if(iam == 0)
        printf("0 :: rectangular grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);

    // get default context
    Cblacs_get(0, 0, &ctx_sys);

    // create a grid and check where I am
    Cblacs_gridinit(&ctx_sys, "R", nrows, ncols);
    Cblacs_gridinfo(ctx_sys, &nrows, &ncols, &myrow, &mycol);

    if(myrow >= 0) { // if I'm in grid
        // get process id (equivalent to `iam`)
        // see https://netlib.org/blacs/BLACS/QRef.html#BLACS_PNUM
        icaller = Cblacs_pnum(ctx_sys, myrow, mycol);

        if(iam == 0) { // parent process receive message from others
            for(LA_INT i=0; i < nrows; i++) {
                for(LA_INT j=0; j < ncols; j++) {
                    if(i != 0 || j != 0) {
                        // receive a 1x1 (general) matrix
                        // See https://netlib.org/blacs/BLACS/QRef.html#RV
                        Cigerv2d(ctx_sys,
                                 1, 1, /* 1x1 array */
                                 &icaller, /* start of the array*/
                                 1, /* lda */
                                 i, j /* receive from process at (i, j) on the grid */
                                 );

                        // is it really the right process who answered? Compute its coordinate on the grid and check it matches
                        // see https://netlib.org/blacs/BLACS/QRef.html#BLACS_PCOORD
                        Cblacs_pcoord(ctx_sys, icaller, &itsrow, &itscol);

                        if(i != itsrow || j != itscol)
                            printf("%lld :: imposter answered, %lld is not at its correct position on the grid :(\n", iam, icaller);
                        else
                            printf("%lld :: process %lld answered correctly\n", iam, icaller);
                    }
                }
            }

        } else {
            // send process id as a 1x1 (general) matrix
            // See https://netlib.org/blacs/BLACS/QRef.html#SD
            Cigesd2d(ctx_sys,
                     1, 1, /* 1x1 array */
                     &icaller, /* start of the array */
                     1, /* lda */
                     0, 0 /* send to process at (0, 0) on the grid */
                     );
        }

        // exit grids
        Cblacs_gridexit(ctx_sys);
    } else
        printf("%lld :: I'm out of grid\n", iam);

    // finalize BLACS
    Cblacs_exit(0);

    return EXIT_SUCCESS;
}

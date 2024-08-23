/* This is a (adapted) translation of https://netlib.org/blacs/BLACS/Examples.html#HELLO.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <mkl_blacs.h>
#include <mkl_scalapack.h>

MKL_INT I_ZERO = 0, I_ONE = 1;

int main(int argc, char* argv[]) {
    MKL_INT iam, nprocs, ctx_sys, nrows, ncols, myrow, mycol, icaller, itscol, itsrow;

    // initialize BLACS &  get default context
    blacs_pinfo(&iam, &nprocs);
    blacs_get(&I_ZERO, &I_ZERO, &ctx_sys);

    // create a rectangular grid
    nrows = (MKL_INT) sqrt((double) nprocs);
    ncols = nprocs / nrows;
    if(iam == 0)
        printf("0 :: rectangular grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);

    // create a grid and check where I am
    blacs_gridinit(&ctx_sys, "R", &nrows, &ncols);
    blacs_gridinfo(&ctx_sys, &nrows, &ncols, &myrow, &mycol);

    if(myrow >= 0) { // if I'm in grid
        // get process id (equivalent to `iam`)
        // see https://netlib.org/blacs/BLACS/QRef.html#BLACS_PNUM
        icaller = blacs_pnum(&ctx_sys, &myrow, &mycol);

        if(iam == 0) { // parent process receive message from others
            for(MKL_INT i=0; i < nrows; i++) {
                for(MKL_INT j=0; j < ncols; j++) {
                    if(i != 0 || j != 0) {
                        // receive a 1x1 (general) matrix
                        // See https://netlib.org/blacs/BLACS/QRef.html#RV
                        igerv2d(&ctx_sys,
                                &I_ONE, &I_ONE, /* 1x1 array */
                                 &icaller, /* start of the array*/
                                 &I_ONE, /* lda */
                                 &i, &j /* receive from process at (i, j) on the grid */
                                 );

                        // is it really the right process who answered? Compute its coordinate on the grid and check it matches
                        // see https://netlib.org/blacs/BLACS/QRef.html#BLACS_PCOORD
                        blacs_pcoord(&ctx_sys, &icaller, &itsrow, &itscol);

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
            igesd2d(&ctx_sys,
                     &I_ONE, &I_ONE, /* 1x1 array */
                     &icaller, /* start of the array */
                     &I_ONE, /* lda */
                     &I_ZERO, &I_ZERO /* send to process at (0, 0) on the grid */
                     );
        }

        // exit grids
        blacs_gridexit(&ctx_sys);
    } else
        printf("%lld :: I'm out of grid\n", iam);

    // finalize BLACS
    blacs_exit(&I_ZERO);

    return EXIT_SUCCESS;
}

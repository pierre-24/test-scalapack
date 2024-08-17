#include <stdio.h>
#include <stdlib.h>

#define LA_INT Int
#ifdef USE_LA_MKL
#include <mkl_scalapack.h>
#define Int MKL_INT
#else
#include <scalapack.h>
#endif
#include "cblacs.h"

/**
 * Find grid params, but ensure that all processors are used
 *
 * @param nprocs number of processors available
 * @param[out] nrows
 * @param[out] ncols
 */
void find_grid_params_all(LA_INT nprocs, LA_INT* nrows, LA_INT* ncols) {
    for(LA_INT i = 1; i*i <= nprocs; i++) {
        if(nprocs % i == 0) {
            *nrows = nprocs / i;
            *ncols = i;
        }
    }
}

/**
 * Find grid params, but ensure that the grid is almost a square.
 * The resulting grid will be `MxN`, where `M=floor(sqrt(procs))` and `M <= N <= M+tol`.
 * Setting `tol=0` thus results in a square grid.
 *
 * @param nprocs number of processors available
 * @param[out] nrows
 * @param[out] ncols
 */
void find_grid_params_rectangular(LA_INT nprocs, LA_INT tol, LA_INT* nrows, LA_INT* ncols) {
    *nrows = *ncols = 1;

    // find square
    while ((*nrows + 1) * (*ncols + 1) <= nprocs) {
        (*nrows)++;
        (*ncols)++;
    }

    // see if we can extend the square a bit
    while ((*nrows) * (*ncols + 1) <= nprocs && (*ncols) <= (*nrows + tol)) {
        (*ncols)++;
    }
}

int main(int argc, char* argv[]) {
    LA_INT iam, nprocs, ctx_sys, ctx_all, ctx_rect, nrows, ncols, myrow, mycol;

    // initialize MPI (via BLACS)
    Cblacs_pinfo(&iam, &nprocs);

    // get default context (most probably zero)
    Cblacs_get(0, 0, &ctx_sys);

    // set a grid for all processes
    // https://www.netlib.org/scalapack/slug/node71.html#secblacscontext
    ctx_all = ctx_sys;
    find_grid_params_all(nprocs, &nrows, &ncols);
    if(iam == 0) {
        printf("0 :: grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);
    }
    Cblacs_gridinit(&ctx_all, "R", nrows, ncols);

    // set a rectangular grid
    ctx_rect = ctx_sys;
    find_grid_params_rectangular(nprocs, 2, &nrows, &ncols);
    if(iam == 0) {
        printf("0 :: rectangular grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);
    }
    Cblacs_gridinit(&ctx_rect, "R", nrows, ncols);

    Cblacs_gridinfo(ctx_all, &nrows, &ncols, &myrow, &mycol); // note: the number of cols & rows is an output as well!
    printf("%lld :: On context %lld, I'm (%lld, %lld)\n", iam, ctx_all, myrow, mycol);

    if(ctx_rect >= 0) {
        Cblacs_gridinfo(ctx_rect, &nrows, &ncols, &myrow, &mycol);
        printf("%lld :: On context %lld, I'm (%lld, %lld)\n", iam, ctx_rect, myrow, mycol);
    }

    // exit grids
    Cblacs_gridexit(ctx_all);

    if(ctx_rect >= 0)
        Cblacs_gridexit(ctx_rect);

    // finalize MPI (via BLACS)
    Cblacs_exit(0);

    return EXIT_SUCCESS;
}

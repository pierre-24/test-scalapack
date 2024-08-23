#include <stdio.h>
#include <stdlib.h>

#include <mkl_blacs.h>

/**
 * Find grid params, but ensure that all processors are used
 *
 * @param nprocs number of processors available
 * @param[out] nrows
 * @param[out] ncols
 */
void find_grid_params_all(MKL_INT nprocs, MKL_INT* nrows, MKL_INT* ncols) {
    for(MKL_INT i = 1; i*i <= nprocs; i++) {
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
void find_grid_params_rectangular(MKL_INT nprocs, MKL_INT tol, MKL_INT* nrows, MKL_INT* ncols) {
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

MKL_INT I_ZERO = 0, I_ONE = 1;

int main(int argc, char* argv[]) {
    MKL_INT iam, nprocs, ctx_sys, ctx_all, ctx_rect, nrows, ncols, myrow, mycol;

    // initialize MPI (via BLACS)
    blacs_pinfo(&iam, &nprocs);

    // get default context (most probably zero)
    blacs_get(&I_ZERO, &I_ZERO, &ctx_sys);

    // set a grid for all processes
    // https://www.netlib.org/scalapack/slug/node71.html#secblacscontext
    // NOTE: to use multiple grid, ctx_sys should not directly be set.
    ctx_all = ctx_sys;
    find_grid_params_all(nprocs, &nrows, &ncols);
    if(iam == 0) {
        printf("0 :: grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);
    }
    blacs_gridinit(&ctx_all, "R", &nrows, &ncols);

    // set a rectangular grid
    ctx_rect = ctx_sys;
    find_grid_params_rectangular(nprocs, 2, &nrows, &ncols);
    if(iam == 0) {
        printf("0 :: rectangular grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);
    }
    blacs_gridinit(&ctx_rect, "R", &nrows, &ncols);

    blacs_gridinfo(&ctx_all, &nrows, &ncols, &myrow, &mycol); // note: the number of cols & rows is an output as well!
    printf("%lld :: On context %lld, I'm (%lld, %lld)\n", iam, ctx_all, myrow, mycol);

    if(ctx_rect >= 0) {
        blacs_gridinfo(&ctx_rect, &nrows, &ncols, &myrow, &mycol);
        printf("%lld :: On context %lld, I'm (%lld, %lld)\n", iam, ctx_rect, myrow, mycol);
    }

    // exit grids
    blacs_gridexit(&ctx_all);

    if(ctx_rect >= 0)
        blacs_gridexit(&ctx_rect);

    // finalize MPI (via BLACS)
    blacs_exit(&I_ZERO);

    return EXIT_SUCCESS;
}

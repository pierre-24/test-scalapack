#include <stdio.h>
#include <stdlib.h>

#include "cblacs.h"

void find_grid_params(LA_INT nprocs, LA_INT* nrows, LA_INT* ncols) {
    *nrows = 1;
    *ncols = 1;

    // square grid
    while (((*nrows + 1) * (*ncols + 1)) <= nprocs) {
        (*nrows)++;
        (*ncols)++;
    }

    // is it possible to extend one side and keep it under nprocs?
    while (((*nrows + 1) * (*ncols)) <= nprocs) {
        (*nrows)++;
    }
}

int main(int argc, char* argv[]) {
    LA_INT iam, nprocs, ctx_sys, ctx_all, nrows, ncols;

    // initialize MPI via BLACS
    Cblacs_pinfo(&iam, &nprocs);
    find_grid_params(14, &nrows, &ncols);
    if(iam == 0) {
        printf("0 :: best grid with %lld procs is %lldx%lld\n", nprocs, nrows, ncols);
    }

    // get default context
    Cblacs_get(0,0, &ctx_sys);

    // set a first grid for all processes
    // https://www.netlib.org/scalapack/slug/node71.html#secblacscontext
    ctx_all = ctx_sys;
    Cblacs_gridinit(&ctx_all, "R", nprocs, 1);

    printf("hello, I'm %lld of %lld\n", iam, nprocs);

    // exit global grid
    Cblacs_gridexit(ctx_all);

    // finalize MPI via BLACS
    Cblacs_exit(0);

    return EXIT_SUCCESS;
}

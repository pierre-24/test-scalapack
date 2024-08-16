#ifndef CBLACS_H
#define CBLACS_H

#ifndef LA_INT
#ifdef USE_MKL
#include <mkl.h>
#define LA_INT MKL_INT
#else
#define STDL_LA_INT int
#endif
#endif

/* wrapper around BLACS functions */

extern void Cblacs_get(LA_INT, LA_INT, LA_INT*);
extern void Cblacs_pinfo(LA_INT*, LA_INT*);
extern void Cblacs_exit(LA_INT);

extern void Cblacs_gridinit(LA_INT*, char const*, LA_INT, LA_INT);
extern void Cblacs_gridinfo(LA_INT, LA_INT*, LA_INT*, LA_INT*, LA_INT*);
extern void Cblacs_barrier(LA_INT , char*);
extern void Cblacs_gridexit(LA_INT);


#endif

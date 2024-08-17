#ifndef HEADER_CBLACS_H
#define HEADER_CBLACS_H

/* Header by cblacs-header.py
 * Generated: 2024-08-17 14:52:58.926179
 * Version cblacs-header.py: https://github.com/pierre-24/cblacs-header/tree/a1f3273e
 * Version scalapack: https://github.com/Reference-ScaLAPACK/scalapack/tree/25935e1a
 */

#include <mpi.h>

/* Macros defined in reference scalapack.
 * See https://github.com/Reference-ScaLAPACK/scalapack/blob/master/BLACS/SRC/Bdef.h
 */
#ifndef Int
#define Int int
#endif // Int

#ifndef F_VOID_FUNC
#define F_VOID_FUNC void
#endif // F_VOID_FUNC

#ifndef F_INT_FUNC
#define F_INT_FUNC Int
#endif // F_INT_FUNC

#ifndef F_DOUBLE_FUNC
#define F_DOUBLE_FUNC double
#endif // F_DOUBLE_FUNC

#ifndef F_CHAR
#define F_CHAR char*
#endif // F_CHAR


/* Declarations
 */

extern void Cigerv2d(Int ConTxt, Int m, Int n, Int* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_freebuff(Int ConTxt, Int Wait);
    
extern void Cigamn2d(Int ConTxt, char* scope, char* top, Int m, Int n, Int* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Ccgamx2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Csgebr2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Ccgamn2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Ccgsum2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int rdest, Int cdest);
    
extern Int Cblacs_pnum(Int ConTxt, Int prow, Int pcol);
    
extern void Cctrbs2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, float* A, Int lda);
    
extern void Cdgamn2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern double Cdcputime00();
    
extern Int Csys2blacs_handle(MPI_Comm SysCtxt);
    
extern void Cstrbr2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Cztrsd2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, double* A, Int lda, Int rdest, Int cdest);
    
extern void Cigsum2d(Int ConTxt, char* scope, char* top, Int m, Int n, Int* A, Int lda, Int rdest, Int cdest);
    
extern void Citrsd2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, Int* A, Int lda, Int rdest, Int cdest);
    
extern void Cdtrbr2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_exit(Int NotDone);
    
extern MPI_Comm Cblacs2sys_handle(Int BlacsCtxt);
    
extern void Cblacs_gridinfo(Int ConTxt, Int* nprow, Int* npcol, Int* myrow, Int* mycol);
    
extern void Ccgebs2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda);
    
extern void Cblacs_pcoord(Int ConTxt, Int nodenum, Int* prow, Int* pcol);
    
extern void Csgebs2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda);
    
extern void Cztrbs2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, double* A, Int lda);
    
extern void Czgerv2d(Int ConTxt, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_gridexit(Int ConTxt);
    
extern void Cstrrv2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Cctrbr2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_gridmap(Int* ConTxt, Int* usermap, Int ldup, Int nprow0, Int npcol0);
    
extern void Cstrsd2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, float* A, Int lda, Int rdest, Int cdest);
    
extern void Csgerv2d(Int ConTxt, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Csgesd2d(Int ConTxt, Int m, Int n, float* A, Int lda, Int rdest, Int cdest);
    
extern void Csgamx2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Cblacs_setup(Int* mypnum, Int* nprocs);
    
extern void Csgsum2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int rdest, Int cdest);
    
extern void Cblacs_abort(Int ConTxt, Int ErrNo);
    
extern void Cdgebr2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Ccgebr2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Cdgamx2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Cztrrv2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_set(Int ConTxt, Int what, Int* val);
    
extern void Cdtrbs2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, double* A, Int lda);
    
extern void Cigamx2d(Int ConTxt, char* scope, char* top, Int m, Int n, Int* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Cfree_blacs_system_handle(Int ISysCtxt);
    
extern void Cblacs_barrier(Int ConTxt, char* scope);
    
extern void Citrrv2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, Int* A, Int lda, Int rsrc, Int csrc);
    
extern double Cdwalltime00();
    
extern void Czgamx2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Cdgebs2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda);
    
extern void Cblacs_gridinit(Int* ConTxt, char* order, Int nprow, Int npcol);
    
extern void Cctrsd2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, float* A, Int lda, Int rdest, Int cdest);
    
extern void Czgebr2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Ccgerv2d(Int ConTxt, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_get(Int ConTxt, Int what, Int* val);
    
extern Int Ckbrid(Int ConTxt, char* scope, Int rsrc, Int csrc);
    
extern void Czgesd2d(Int ConTxt, Int m, Int n, double* A, Int lda, Int rdest, Int cdest);
    
extern Int Ckrecvid(Int ConTxt, Int rsrc, Int csrc);
    
extern void Cdgsum2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int rdest, Int cdest);
    
extern void Cigesd2d(Int ConTxt, Int m, Int n, Int* A, Int lda, Int rdest, Int cdest);
    
extern void Cstrbs2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, float* A, Int lda);
    
extern void Cdgesd2d(Int ConTxt, Int m, Int n, double* A, Int lda, Int rdest, Int cdest);
    
extern void Cigebr2d(Int ConTxt, char* scope, char* top, Int m, Int n, Int* A, Int lda, Int rsrc, Int csrc);
    
extern void Cdtrrv2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Cblacs_pinfo(Int* mypnum, Int* nprocs);
    
extern void Cztrbr2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Citrbr2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, Int* A, Int lda, Int rsrc, Int csrc);
    
extern void Cigebs2d(Int ConTxt, char* scope, char* top, Int m, Int n, Int* A, Int lda);
    
extern Int Cksendid(Int ConTxt, Int rdest, Int cdest);
    
extern void Cdtrsd2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, double* A, Int lda, Int rdest, Int cdest);
    
extern void Cdgerv2d(Int ConTxt, Int m, Int n, double* A, Int lda, Int rsrc, Int csrc);
    
extern void Czgebs2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda);
    
extern void Citrbs2d(Int ConTxt, char* scope, char* top, char* uplo, char* diag, Int m, Int n, Int* A, Int lda);
    
extern void Czgsum2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int rdest, Int cdest);
    
extern void Ccgesd2d(Int ConTxt, Int m, Int n, float* A, Int lda, Int rdest, Int cdest);
    
extern void Csgamn2d(Int ConTxt, char* scope, char* top, Int m, Int n, float* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern Int Ckbsid(Int ConTxt, char* scope);
    
extern void Czgamn2d(Int ConTxt, char* scope, char* top, Int m, Int n, double* A, Int lda, Int* rA, Int* cA, Int ldia, Int rdest, Int cdest);
    
extern void Cctrrv2d(Int ConTxt, char* uplo, char* diag, Int m, Int n, float* A, Int lda, Int rsrc, Int csrc);
    

extern F_VOID_FUNC igerv2d_(Int* ConTxt, Int* m, Int* n, Int* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_freebuff_(Int* ConTxt, Int* Wait);
    
extern F_VOID_FUNC igamn2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, Int* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC cgamx2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC sgebr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC cgamn2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC cgsum2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_INT_FUNC blacs_pnum_(Int* ConTxt, Int* prow, Int* pcol);
    
extern F_VOID_FUNC ctrbs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda);
    
extern F_VOID_FUNC dgamn2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_DOUBLE_FUNC dcputime00_();
    
extern Int sys2blacs_handle_(Int* SysCtxt);
    
extern F_VOID_FUNC strbr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC ztrsd2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC igsum2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, Int* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC itrsd2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, Int* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC dtrbr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_exit_(Int* NotDone);
    
extern Int blacs2sys_handle_(Int* BlacsCtxt);
    
extern F_VOID_FUNC blacs_gridinfo_(Int* ConTxt, Int* nprow, Int* npcol, Int* myrow, Int* mycol);
    
extern F_VOID_FUNC cgebs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda);
    
extern F_VOID_FUNC blacs_pcoord_(Int* ConTxt, Int* nodenum, Int* prow, Int* pcol);
    
extern F_VOID_FUNC sgebs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda);
    
extern F_VOID_FUNC ztrbs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda);
    
extern F_VOID_FUNC zgerv2d_(Int* ConTxt, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_gridexit_(Int* ConTxt);
    
extern F_VOID_FUNC strrv2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC ctrbr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_gridmap_(Int* ConTxt, Int* usermap, Int* ldup, Int* nprow0, Int* npcol0);
    
extern F_VOID_FUNC strsd2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC sgerv2d_(Int* ConTxt, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC sgesd2d_(Int* ConTxt, Int* m, Int* n, float* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC sgamx2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC blacs_setup_(Int* mypnum, Int* nprocs);
    
extern F_VOID_FUNC sgsum2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC blacs_abort_(Int* ConTxt, Int* ErrNo);
    
extern F_VOID_FUNC dgebr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC cgebr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC dgamx2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC ztrrv2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_set_(Int* ConTxt, Int* what, Int* val);
    
extern F_VOID_FUNC dtrbs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda);
    
extern F_VOID_FUNC igamx2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, Int* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern void free_blacs_system_handle_(Int* ISysCxt);
    
extern F_VOID_FUNC blacs_barrier_(Int* ConTxt, F_CHAR scope);
    
extern F_VOID_FUNC itrrv2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, Int* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_DOUBLE_FUNC dwalltime00_();
    
extern F_VOID_FUNC zgamx2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC dgebs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda);
    
extern F_VOID_FUNC blacs_gridinit_(Int* ConTxt, F_CHAR order, Int* nprow, Int* npcol);
    
extern F_VOID_FUNC ctrsd2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC zgebr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC cgerv2d_(Int* ConTxt, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_get_(Int* ConTxt, Int* what, Int* val);
    
extern F_INT_FUNC kbrid_(Int* ConTxt, F_CHAR scope, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC zgesd2d_(Int* ConTxt, Int* m, Int* n, double* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_INT_FUNC krecvid_(Int* ConTxt, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC dgsum2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC igesd2d_(Int* ConTxt, Int* m, Int* n, Int* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC strbs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda);
    
extern F_VOID_FUNC dgesd2d_(Int* ConTxt, Int* m, Int* n, double* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC igebr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, Int* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC dtrrv2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC blacs_pinfo_(Int* mypnum, Int* nprocs);
    
extern F_VOID_FUNC ztrbr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC itrbr2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, Int* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC igebs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, Int* A, Int* lda);
    
extern F_INT_FUNC ksendid_(Int* ConTxt, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC dtrsd2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, double* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC dgerv2d_(Int* ConTxt, Int* m, Int* n, double* A, Int* lda, Int* rsrc, Int* csrc);
    
extern F_VOID_FUNC zgebs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda);
    
extern F_VOID_FUNC itrbs2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, Int* A, Int* lda);
    
extern F_VOID_FUNC zgsum2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC cgesd2d_(Int* ConTxt, Int* m, Int* n, float* A, Int* lda, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC sgamn2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, float* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_INT_FUNC kbsid_(Int* ConTxt, F_CHAR scope);
    
extern F_VOID_FUNC zgamn2d_(Int* ConTxt, F_CHAR scope, F_CHAR top, Int* m, Int* n, double* A, Int* lda, Int* rA, Int* cA, Int* ldia, Int* rdest, Int* cdest);
    
extern F_VOID_FUNC ctrrv2d_(Int* ConTxt, F_CHAR uplo, F_CHAR diag, Int* m, Int* n, float* A, Int* lda, Int* rsrc, Int* csrc);
    

#endif // HEADER_CBLACS_H
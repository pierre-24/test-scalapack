#ifndef HEADER_CPBLAS_H
#define HEADER_CPBLAS_H

/* Header by scalapack_files_create.create_cpblas
 * Generated: 2024-08-18 15:20:34.858885
 * Version scalapack_files_create.create_cpblas: https://github.com/pierre-24/scalapack-c-headers/tree/13421c2b
 * Version scalapack: https://github.com/Reference-ScaLAPACK/scalapack/tree/25935e1a
 */

/* Macros defined in reference scalapack.
 * See https://github.com/Reference-ScaLAPACK/scalapack/blob/master/PBLAS/SRC/pblas.h
 */
#ifndef Int
#define Int int
#endif // Int

#ifndef F_CHAR_T
#define F_CHAR_T char*
#endif // F_CHAR_T


/* Declarations
 */

extern void pcher_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pdasymv_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pctradd_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pdscal_(Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pzdotu_(Int* N, double* DOT, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcgemv_(F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcgerc_(Int* M, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pzsymm_(F_CHAR_T SIDE, F_CHAR_T UPLO, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdtrsm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB);
extern void pzsyrk_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pctrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pcagemv_(F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzher2_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, double* A, Int* IA, Int* JA, Int* DESCA);
extern void psswap_(Int* N, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzahemv_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzscal_(Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pztrmm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB);
extern void pzgerc_(Int* M, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, double* A, Int* IA, Int* JA, Int* DESCA);
extern void pstran_(Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void psgemv_(F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzcopy_(Int* N, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void psgeadd_(F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pzhemv_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pctrsm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB);
extern void pdtradd_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void psamax_(Int* N, float* AMAX, Int* INDX, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pstrmm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB);
extern void pcgeadd_(F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pssymv_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void psger_(Int* M, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pdsyr2_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, double* A, Int* IA, Int* JA, Int* DESCA);
extern void pcher2_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pdamax_(Int* N, double* AMAX, Int* INDX, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pccopy_(Int* N, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pddot_(Int* N, double* DOT, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcsyrk_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pcswap_(Int* N, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcahemv_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzdotc_(Int* N, double* DOT, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzaxpy_(Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void psasymv_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pctranu_(Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pzgemv_(F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pchemv_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcscal_(Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdswap_(Int* N, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pztranc_(Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pcgemm_(F_CHAR_T TRANSA, F_CHAR_T TRANSB, Int* M, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pstrsv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pscopy_(Int* N, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzgemm_(F_CHAR_T TRANSA, F_CHAR_T TRANSB, Int* M, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pztrsv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void psnrm2_(Int* N, float* NORM2, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdgemv_(F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pztranu_(Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pztradd_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pztrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pzsyr2k_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pcsyr2k_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pscasum_(Int* N, float* ASUM, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pzgeadd_(F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdsyr2k_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdger_(Int* M, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, double* A, Int* IA, Int* JA, Int* DESCA);
extern void pdagemv_(F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcherk_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pcsscal_(Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdaxpy_(Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void psaxpy_(Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pssymm_(F_CHAR_T SIDE, F_CHAR_T UPLO, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pzdscal_(Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pcher2k_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pctranc_(Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pstrsm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB);
extern void pdtran_(Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdgeadd_(F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pcdotu_(Int* N, float* DOT, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzherk_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdcopy_(Int* N, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pdtrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdzasum_(Int* N, double* ASUM, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdasum_(Int* N, double* ASUM, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pscnrm2_(Int* N, float* NORM2, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdatrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pdgemm_(F_CHAR_T TRANSA, F_CHAR_T TRANSB, Int* M, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pzher_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* A, Int* IA, Int* JA, Int* DESCA);
extern void pdsyrk_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pzamax_(Int* N, double* AMAX, Int* INDX, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pssyr2_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pcgeru_(Int* M, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pdsyr_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* A, Int* IA, Int* JA, Int* DESCA);
extern void pdznrm2_(Int* N, double* NORM2, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pchemm_(F_CHAR_T SIDE, F_CHAR_T UPLO, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pcamax_(Int* N, float* AMAX, Int* INDX, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pzhemm_(F_CHAR_T SIDE, F_CHAR_T UPLO, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdsymm_(F_CHAR_T SIDE, F_CHAR_T UPLO, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pdtrmm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB);
extern void pzher2k_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB, double* BETA, double* C, Int* IC, Int* JC, Int* DESCC);
extern void pcatrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcaxpy_(Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pdtrsv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pssyr2k_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void psscal_(Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdsymv_(F_CHAR_T UPLO, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pztrsm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* B, Int* IB, Int* JB, Int* DESCB);
extern void pctrmm_(F_CHAR_T SIDE, F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB);
extern void psgemm_(F_CHAR_T TRANSA, F_CHAR_T TRANSB, Int* M, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pcsymm_(F_CHAR_T SIDE, F_CHAR_T UPLO, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* B, Int* IB, Int* JB, Int* DESCB, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void psdot_(Int* N, float* DOT, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void psagemv_(F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pssyr_(F_CHAR_T UPLO, Int* N, float* ALPHA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* A, Int* IA, Int* JA, Int* DESCA);
extern void pssyrk_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* N, Int* K, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void picopy_(Int* N, Int* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, Int* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzagemv_(F_CHAR_T TRANS, Int* M, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzswap_(Int* N, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void psatrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* BETA, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pzgeru_(Int* M, Int* N, double* ALPHA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY, double* A, Int* IA, Int* JA, Int* DESCA);
extern void pstradd_(F_CHAR_T UPLO, F_CHAR_T TRANS, Int* M, Int* N, float* ALPHA, float* A, Int* IA, Int* JA, Int* DESCA, float* BETA, float* C, Int* IC, Int* JC, Int* DESCC);
extern void pstrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pzatrmv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, double* ALPHA, double* A, Int* IA, Int* JA, Int* DESCA, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, double* BETA, double* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pcdotc_(Int* N, float* DOT, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX, float* Y, Int* IY, Int* JY, Int* DESCY, Int* INCY);
extern void pctrsv_(F_CHAR_T UPLO, F_CHAR_T TRANS, F_CHAR_T DIAG, Int* N, float* A, Int* IA, Int* JA, Int* DESCA, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void psasum_(Int* N, float* ASUM, float* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);
extern void pdnrm2_(Int* N, double* NORM2, double* X, Int* IX, Int* JX, Int* DESCX, Int* INCX);

#endif // HEADER_CPBLAS_H
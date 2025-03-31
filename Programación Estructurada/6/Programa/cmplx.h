#ifndef STRCT
#define STRCT

typedef struct{
  float r, bi;
} Cmplx_t;

void getcmplx(Cmplx_t *, int);  
void printRec(Cmplx_t);
void printPol(Cmplx_t);
void sumCmplx(Cmplx_t, Cmplx_t, Cmplx_t *);
void resCmplx(Cmplx_t, Cmplx_t, Cmplx_t *);
void multComplx(Cmplx_t, Cmplx_t, Cmplx_t *);
void divComplx(Cmplx_t, Cmplx_t, Cmplx_t *);



#endif
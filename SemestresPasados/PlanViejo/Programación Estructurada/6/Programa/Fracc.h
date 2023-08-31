#ifndef FRACC
#define FRACC

typedef struct{
  int num, den;
} Fracc_t;


void getFracc(Fracc_t *, int);
void printFracc(Fracc_t);
void sumFracc(Fracc_t, Fracc_t, Fracc_t *);
void resFracc(Fracc_t, Fracc_t, Fracc_t *);
void multFracc(Fracc_t, Fracc_t, Fracc_t *);
void divFracc(Fracc_t, Fracc_t, Fracc_t *);
void redFracc(Fracc_t *);
int mcd(Fracc_t);
#endif
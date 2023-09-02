#ifndef VECT
#define VECT

typedef struct{
  float i;
  float j;
  float k;
} Vect_t;

void getVect(Vect_t *, int);
void printVect(Vect_t);
float modVect(Vect_t);
void sumVect(Vect_t, Vect_t, Vect_t *);
void resVect(Vect_t, Vect_t, Vect_t *);
float escVect(Vect_t, Vect_t);
void escXvect(Vect_t *, float);
void vectVect(Vect_t, Vect_t, Vect_t *);

#endif
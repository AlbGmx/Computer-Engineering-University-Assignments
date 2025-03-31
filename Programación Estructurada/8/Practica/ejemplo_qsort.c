//fuente: http://www.cplusplus.com/reference/cstdlib/qsort/

#include <stdio.h>    
#include <stdlib.h>

int values[] = { 40, 10, 100, 90, 20, 25 };
float valuesf[] = { 40.1, 10.4, 100.7, 90.9, 20.7, 25.7 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int comparef (const void * a, const void * b)
{
  return ( *(float*)a - *(float*)b );
}

int main ()
{
  int n, size;
  size=sizeof(valuesf)/sizeof(valuesf[0]);
  qsort (valuesf, size, sizeof(float), compare);
  for (n=0; n<size; n++)
     printf ("%f ",valuesf[n]);
  return 0;
}

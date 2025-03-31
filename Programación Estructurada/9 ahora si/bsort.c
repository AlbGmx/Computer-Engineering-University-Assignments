//BubbleSort 
#include <stdio.h>

int main(){
  int i,j, aux, k[10]={6,5,5,2,4,3,2,4,3,5};
  for(i=0; i<(sizeof(k)/sizeof(int))-1; i++){
    for (j=i+1; j<(sizeof(k)/sizeof(int)); j++){
      if(k[i]>k[j]) {
        aux=k[i];
        k[i]=k[j];
        k[j]=aux;
      }
    }
  }
  printf("\n");
  for(i=0; i<sizeof(k)/sizeof(int); i++) printf("valor k[%d] = %d\n", i, k[i]);

  return 0;
}
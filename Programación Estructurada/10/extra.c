#include "bits.h"

int main(){
  unsigned int num=0xabcdfe1, num2=0xab;

  printf("Suma de "); display(num, UNSIGNED_INT_SIZE); 
  printf("y       "); display(num, UNSIGNED_INT_SIZE); 
  display(add(num, num2),UNSIGNED_INT_SIZE);

  puts("Complemento a 2 de "); display(num, UNSIGNED_INT_SIZE);
  display(complemento2(num), UNSIGNED_INT_SIZE);

  return 0;
}
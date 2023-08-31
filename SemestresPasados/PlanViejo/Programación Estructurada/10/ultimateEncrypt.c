#include "bits.h"

int main(int argc, char *argv[]){
  double time=0;
  char crypt[50];
  if(argc<3){
    puts("Error de parametros \nEjemplo de aplicacion: ultimateEncrypt.exe archivo.txt 148 encriptado.txt");
    exit(-1);
  }
  addCrpyt(argv[1], crypt);
  if (argc==3) time = encryptFile(argv[1], argv[2], crypt);
  else time = encryptFile(argv[1], argv[2], argv[3]);
  printf("\nTiempo de ejecucion: %3f\n", time);
  return 0;
}

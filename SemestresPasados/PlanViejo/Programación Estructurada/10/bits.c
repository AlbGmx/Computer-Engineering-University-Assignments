#include "bits.h" 

void display(int valor, unsigned char nbits){
  unsigned int mask, cnt=1;
  mask=0x01<<(nbits-1);
  while(mask){
    printf("%d",(valor&mask)>0); 
    if(!(cnt%8)) printf(" ");
    mask>>=1;
    cnt++;
  }
  puts("");
}

unsigned int valor_clearbit( unsigned int valor, unsigned char pos){
  unsigned int mask=0x01;
  mask<<=pos-1;
  
  return (valor&(~mask));  
}

unsigned int valor_setbit( unsigned int valor, unsigned char pos){
  unsigned int mask=0x01;
  mask<<=pos-1;
  return (valor|mask);  
}

unsigned char getbit( unsigned int valor, unsigned char pos){
  unsigned int mask=0x01;
  mask<<=pos-1;
  if(valor&mask) return 1;
  return 0;  
}

unsigned int togglebit( unsigned int valor, unsigned char pos){
  unsigned int mask=0x01;
  mask<<=pos-1;
  return valor^mask;  
}
unsigned int introtright(unsigned int valor, unsigned int loc){
  unsigned int mask=0x01,r;
  r=valor;
  while (loc){
    if(r&mask) {
      r>>=1;
      r=valor_setbit(r,UNSIGNED_INT_SIZE);
    }
    else r>>=1;
    loc--;
  }
  return r;
}
unsigned int introtleft(unsigned int valor, unsigned int loc){
  unsigned int mask=0x01,r;
  r=valor;
  mask<<=UNSIGNED_INT_SIZE-1;
  while (loc){
    if(r&mask) {
      r<<=1;
      r=valor_setbit(r,1);
    }
    else r<<=1;
    loc--;
  }
  return r;
}
unsigned char byterotright(unsigned char valor, unsigned int loc){
  unsigned char mask=0x01,r;
  r=valor;
  while (loc){
    if(r&mask) {
      r>>=1;
      r=valor_setbit(r,UNSIGNED_CHAR_SIZE);
    }
    else r>>=1;
    loc--;
  }
  return r;
}
unsigned char byterotleft(unsigned char valor, int loc){
  unsigned char mask=0x01,r;
  r=valor;
  mask<<=UNSIGNED_CHAR_SIZE-1;
  while (loc){
    if(r&mask) {
      r<<=1;
      r=valor_setbit(r,1);
    }
    else r<<=1;
    loc--;
  }
  return r;
}
unsigned char getbyte(unsigned int valor, unsigned char pos){
  unsigned int mask=0xff;
  if(pos && pos<9){}
  else if(pos>=9 && pos<17)  valor>>8;
  else if(pos>=17 && pos<25) valor>>16;
  else if(pos>=25 && pos<33) valor>>24;
  
  return valor&mask;  
}

void encryptMsg(char* mensaje, unsigned char clave){
  int i;
  for(i=0; i<strlen(mensaje); i++) mensaje[i]=mensaje[i]^clave;
}

double encryptFile(char *origin, char *clave, char *destino){
  clock_t startFunction = clock();
  unsigned char aux, *temp=clave;

  FILE *orgnPtr=NULL, *destPtr=NULL;
  if ( strcmp(origin, destino)==0 ){
    puts("Problemas con nombre de fuente y/o destino");
    exit(-1);
  }
  orgnPtr=fopen(origin, "rb");
  destPtr=fopen(destino, "wb");
  
  if(!orgnPtr || !destPtr){
    puts("Error al abrir archivo");
    exit(-1);
  }


  while(fread(&aux, sizeof(char), 1, orgnPtr)>0){
    aux^=*(clave++);
    if(!*clave) clave=temp;
    fwrite(&aux, sizeof(char), 1, destPtr);
  }
  clock_t endFunction = clock();

  fclose(orgnPtr);
  fclose(destPtr);
  return (((double)(endFunction-startFunction))/CLOCKS_PER_SEC);
}

void addCrpyt(char* name, char dest[50]){
  int i=(strlen(name)- strlen(strrchr(name,'.')));
  strcpy(dest, name);
  dest[i+1]='.';
  dest[i+1]='c';
  dest[i+2]='r';
  dest[i+3]='y';
  dest[i+4]='p';
  dest[i+5]='t';
  dest[i+6]='\x0';
}

unsigned int add(unsigned int uno, unsigned int dos){
  unsigned int r=0x00, i, aux;
  for(i=1; i<=UNSIGNED_INT_SIZE; i++){
    aux=1+i;
    if(getbit(uno,i) && getbit(dos,i)){
      while(getbit(uno, aux)){
        if(aux>UNSIGNED_INT_SIZE){
          puts("Error: dimensiones excedentes");
          exit(-1);
        }
        uno=valor_clearbit(uno,aux);
        aux++;
      }
      uno=valor_setbit(uno,aux);
      r=valor_clearbit(r,i);
    }
    else if(getbit(uno,i) || getbit(dos,i)){
      r=valor_setbit(r,i);
    }
    else r=valor_clearbit(r,i); 
  }
  return r;
}

unsigned int complemento2(unsigned int num){
  return (add(~num,0x01));
}


//unsigned int add(unsigned int uno, unsigned int dos){
//  unsigned int r=0x00, i, aux, bol=0x00;
//  for(i=1; i<=UNSIGNED_INT_SIZE; i++){
//    aux=1+i;
//    if(getbit(uno,i) && getbit(dos,i)){
//      r=valor_clearbit(r,i);
//    }
//    else if(getbit(uno,i) && getbit(dos,i)){
//    else if(getbit(dos,i)){ 
//    
//
//    }
//     
//    else r=valor_clearbit(r,i);
//  
//  
//  }
//
//  return r;
//}

















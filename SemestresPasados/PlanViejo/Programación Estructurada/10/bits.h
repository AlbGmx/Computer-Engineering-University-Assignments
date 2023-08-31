#ifndef BITS
#define BITS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define UNSIGNED_INT_SIZE 32
#define UNSIGNED_CHAR_SIZE 8

void display(int, unsigned char);
unsigned int valor_clearbit(unsigned int, unsigned char);
unsigned int valor_setbit(unsigned int, unsigned char);
unsigned char getbit(unsigned int, unsigned char);
unsigned int togglebit(unsigned int, unsigned char);
unsigned int introtright(unsigned int, unsigned int);
unsigned int introtleft(unsigned int, unsigned int);
unsigned char byterotright(unsigned char, unsigned int);
unsigned char byterotleft(unsigned char, int);
unsigned char getbyte(unsigned int, unsigned char);
void encryptMsg(char*, unsigned char);
double encryptFile(char*, char*, char*);
void addCrpyt(char*, char[]);
unsigned int add(unsigned int, unsigned int);
unsigned int complemento2(unsigned int);
unsigned int sub(unsigned int, unsigned int);
#endif
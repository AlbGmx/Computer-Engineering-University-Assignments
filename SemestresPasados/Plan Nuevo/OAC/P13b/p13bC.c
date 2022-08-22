#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "ppi.h"
extern uint8_t _setBit  (uint8_t, uint8_t);
extern uint8_t _clearBit(uint8_t, uint8_t);
extern uint8_t _notBit  (uint8_t, uint8_t);
extern uint8_t _testBit (uint8_t, uint8_t);

uint8_t setBitPort     (uint8_t, uint8_t,  uint16_t);
uint8_t clearBitPort  (uint8_t, uint8_t,  uint16_t);
uint8_t notBitPort     (uint8_t, uint8_t,  uint16_t);
uint8_t testBitPort    (uint8_t, uint16_t);

int main()
{
   //Inicio del setup
   const char * device = "/dev/ttyUSB0";
   set_dev( device );
   sleep(5);
   outp_b( 0x43, 0x90 );
   sleep(1);
   printf("Ctl: %X \n", inp_b(0x43) );
   // Final del setup
   // 0x40 puerto A

   uint8_t x = inp_b(0x40);
   uint16_t portA = 0x40;
   uint16_t portB = 0x41;
   printf(" inport --> PA:%02x ", x = setBitPort(x, 3, portB));
   printf("clear bit 1, puerto B = %x", x = clearBitPort(x, 1, portB));
   printf("clear bit 4, puerto B = %x", x = clearBitPort(x, 4, portB));
   printf("clear bit 7, puerto B = %x", x = clearBitPort(x, 7, portB));
   printf("not bit 2, puerto B = %x", x = notBitPort(x, 2, portB));
   printf("not bit 3, puerto B = %x", x = notBitPort(x, 3, portB));
   printf("not bit 4, puerto B = %x", x = notBitPort(x, 4, portB));
   printf("not bit 5, puerto B = %x", x = notBitPort(x, 5, portB));
   printf("not bit 7, puerto B = %x", x = notBitPort(x, 7, portB));
   printf("test bit 1, puerto B = %x", x = testBitPort(1, portB));
   printf("test bit 4, puerto B = %x", x = testBitPort(4, portB));
   printf("test bit 7, puerto B = %x", x = testBitPort(7, portB));

   close_dev();
   return 0;
}

uint8_t setBitPort(uint8_t dato, uint8_t numBit, uint16_t puerto){
   int8_t x = 0;
   int8_t data = _setBit(dato,numBit);
   outp_b( puerto,dato );
	printf(" inport  --> PB:%02x\n", x = inp_b( 0x41) );
   return x;
}

uint8_t clearBitPort(uint8_t dato, uint8_t numBit, uint16_t puerto){
   int8_t x = 0;
   int8_t data = _clearBit(dato,numBit);
   outp_b( puerto,dato );
	printf(" inport  --> PB:%02x\n", x = inp_b( 0x41) );
   return x;
}

uint8_t notBitPort(uint8_t dato, uint8_t numBit, uint16_t puerto){
   int8_t x = 0;
   int8_t data = _notBit(dato,numBit);
   outp_b( puerto,dato );
	printf(" inport  --> PB:%02x\n", x = inp_b( 0x41) );
   return x;
}

uint8_t testBitPort(uint8_t numBit, uint16_t puerto){
   int8_t x = inp_b(puerto);
   int8_t data = _testBit(x,numBit); 
   outp_b( puerto,data );
	printf(" inport  --> PB:%02x\n", x = inp_b( 0x41) );
   return x;
}
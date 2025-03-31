#include <stdio.h>
extern unsigned char _setBit (unsigned char, unsigned char);
extern unsigned char _clearBit (unsigned char, unsigned char);
extern unsigned char _notBit (unsigned char, unsigned char);
extern unsigned char _testBit (unsigned char, unsigned char);
int main(void)
{
   unsigned char x = 0x0b3;
   printf("x = %x\n", x);
   printf("_setBit(x,3) = %x\n", x = _setBit(x,3));
   printf("_clearBit(x,1) = %x\n", x = _clearBit(x,1));
   printf("_clearBit(x,4) = %x\n", x = _clearBit(x,4));
   printf("_clearBit(x,7) = %x\n", x = _clearBit(x,7));
   printf("_notBit(x,2)) = %x\n", x = _notBit(x,2));
   printf("_notBit(x,3)) = %x\n", x = _notBit(x,3));
   printf("_notBit(x,4)) = %x\n", x = _notBit(x,4));
   printf("_notBit(x,5)) = %x\n", x = _notBit(x,5));
   printf("_notBit(x,7)) = %x\n", x = _notBit(x,7));
   printf("_testBit(x,1) = %x\n", _testBit(x,1));
   printf("_testBit(x,4) = %x\n", _testBit(x,4));
   printf("_testBit(x,7) = %x\n", _testBit(x,7));
   

   return 0;
}

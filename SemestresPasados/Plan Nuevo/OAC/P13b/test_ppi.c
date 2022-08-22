

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "ppi.h"


int main()
{

  const char * device = "/dev/ttyUSB0";

  set_dev( device );
  sleep(5);

  outp_b( 0x43, 0x90 );
  sleep(1);
  printf("Ctl: %X \n", inp_b(0x43) );

  for(int i=0; i<=255; i++) {
        uint8_t x = inp_b(0x40);
	printf(" inport --> PA:%02x ", x );
        outp_b( 0x41,x );
	printf(" inport  --> PB:%02x\n", inp_b( 0x41) );
	//printf(" PB:%x\n" , inp_b( 0x41 ) );
	sleep(0.25);
  }

  close_dev();

  return 0;
}


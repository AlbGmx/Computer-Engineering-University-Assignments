#define _SFR_ASM_COMPAT 1
#define __SFR_OFFSET 0
#include <avr/io.h>

.global Delay
Delay:
   push r24
delayLoop:
   cpi r24,1
   breq delay1ms
   rcall delayAux
   dec r24
   jmp delayLoop
end:
   pop r24
   ret

delay1ms:
	ldi r26,68
   nop
x1Loop:
   ldi r27,58
y1Loop:
   nop
   dec r27
	brne y1Loop
	dec r26
	brne x1Loop
   jmp end

delayAux:
	ldi r26,73
xLoop:
   ldi r27,72
yLoop:
   dec r27
	brne yLoop
	dec r26
	brne xLoop
   ret

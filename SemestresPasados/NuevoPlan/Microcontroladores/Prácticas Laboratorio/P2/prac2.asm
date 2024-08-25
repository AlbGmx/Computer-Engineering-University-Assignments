;/*
; * Autor: Emmanuel Alberto Gómez Cárdenas
; * Fecha: 25/09/2023
; * Descripcion: Practica 2, AVR Studio
; * Laboratorio de la clase Microcontroladores
; */
.INCLUDE "m328Pdef.inc"

.equ INIT_VALUE  = 0x01	; Port C 
.equ CONFIG_PORT = 0xff	; Direction register Port is DDRC
				
;------------- init PORTS ----------------------------------------------------------------------------------------------
	ldi R24,CONFIG_PORT
	out DDRC,R24

	ldi R24,INIT_VALUE
   ldi r25,1
   mov r7,r25

;------------- main loop -----------------------------------------------------------------------------------------------
next:
   tst r7
   breq shiftLeft
   sbrc r24, 0
   jmp rotateRight
   lsr r24
   jmp printOutput

rotateRight:
   ldi r24, 1<<7
   jmp printOutput

shiftLeft:
   sbrc r24, 7
   jmp rotateLeft
   lsl r24
   jmp printOutput

rotateLeft:
   ldi r24, 1

printOutput:
	out PORTC,R24
	jmp next

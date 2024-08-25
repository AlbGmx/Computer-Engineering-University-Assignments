;/*
; * Autor: Emmanuel Alberto Gómez Cárdenas
; * Fecha: 25/09/2023
; * Descripcion: Practica 3, Retardos
; * Laboratorio de la clase Microcontroladores
; */
.INCLUDE "m328pdef.inc" ; Include Register/Bit Definitions for the 328p
;**** incluir en la inicialización del archivo Prac3.asm
	sbi DDRB,PB1 ; Programa PE1 como salida
	sbi PORTB,PB1 ; Escribir 1 en PE1
	clr r16 
	sts UCSR0B,r16 
;********************** Ciclo Principal ********************************************************************************
next: 
   sbi PORTB,5 ; Escribir 1 en PB5
;  rcall miRetardo 
   cbi PORTB,5 ; Escribir 0 en PB5
;  rcall miRetardo
;*********************** prueba de PresentarBits ***********************************************************************
	ldi r24,0x55
	rcall PresentarBits
	ldi r24,0x41
	rcall PresentarBits
	ldi r24,0x42
	rcall PresentarBits
	ldi r24,0x43
	rcall PresentarBits
	cbi PORTB,5
	rjmp next
;********************** F U N C I O N E S ******************************************************************************
;  miRetardo
;  Descripción: Retardo de X mS basado en ciclos anidados
;  Registros usados: R24, R25 y R26
;  Valores de Retorno: N/A
;  Nota: Esto registros son modificados y se pierde el valor original
;***********************************************************************************************************************
miRetardo:
	clr r24
nxt0: 	
   clr r25
nxt1: 	
   clr r26
nxt2: 	
   dec r26
	brne nxt2
	dec r25
	brne nxt1
	dec r24
	brne nxt0
   ret
;**************** Algoritmo PresentarBits ******************************************************************************
PresentarBits:
;  Consideraciones:
;  El bit PE1 ya está programado como salida y se le ha escrito un 1 lógico inicio:

;  Paso 1: Poner en bajo (0 lógico) a PE1.
   cbi PORTB, PB5

;  Paso 2: Esperar un retardo de 103uS.
   rcall delay103usWithRCall

;  Paso 3: Pasar el bit LSB (menos significativo) de R24 a PE1.
   ldi r25,7   ;r25 will be used to cicle the r24
loopRegister:  ;Loop to cycle all the register bits
   sbrc r24,0 
   jmp setBit
   cbi PORTB, PB5
	jmp step4
setBit: 
   sbi PORTB, PB5

;  Paso 4: Esperar un retardo de 103uS.
step4:
   rcall delay103usWithRCall

;  Paso 5: Hacer corrimiento a la derecha a R24.
   lsr r24

;  Paso 6: Si no es el último bit ir al paso 3 de lo contrario continuar
;  Nota: El último bit es cuando el MSB original ha llegado al LSB
   dec r25
   brne loopRegister

;  Paso 7: Poner PE1 alto (1 lógico). Nota: se deja como estaba al inicio
   sbi PORTB, PB5

;  Paso 8: Esperar un retardo de 103uS.
   rcall delay103usWithRCall

;  fin:   
   ret
;  delay103us
;  Descripción: Retardo de 103 micro segundos basado en ciclos anidados
;  Registros usados: R24, R25
;  Valores de Retorno: N/A
;  Nota: Esto registros son modificados y se pierde el valor original
;******************Algortitmo delay 103 microseconds********************************************************************
delay103us:    ;Cycles used
	ldi r26,4   ;1
xLoop: 	
   ldi r27,136 ;x
yLoop:	
   dec r27     ;xy
	brne yLoop  ;(2y-1)(x)
	dec r26     ;x
	brne xLoop  ;(2x-1)
   ret         ; 4
;********************* C Á L C U L O S *********************************************************************************
;  Micro controller freq = 16MHz, period = 1/16MHz => 62.5nanoseconds
;  Delay needed = 103microseconds => 103000 nanoseconds
 
;  Cicles needed to achieve desired delay = cicles/period
;  cicles = 103000ns / 62.5ns = 1648 cicles

;Total cycles in delay103us function 1 + x + xy + x(2y-1) + x + (2x-1) + 4
;  reduce equation => 3xy + 3x + 4
;  Find x and y values so equation equals 1648 => 3xy + 3x + 4 = 1648 where 0<x<256 and 0<y<256
;  There are only 2 integer solutions that satisfy the equation => when x = 4 and y = 136 or when x = 137 and y = 3

;  If we contemplate the Rcall into the equation we get 3 extra cycles so the final equation will be
;  3xy + 3x + 7 = 1648 => reduced to 3xy + 3x = 1641
;  There are no integer solutions that satisfy the equation, but we could make use of the nop instruction inside the 
;  x loop so we can get an integer solution, this will give us 3xy + 4x = 1641 only when x = 3 and y = 181

;******************Algortitmo delay 103 microseconds contemplating rCall************************************************
delay103usWithRCall:        ;Cycles used
	ldi r26,3   ;1
x1Loop: nop    ;x
   ldi r27,181 ;x
y1Loop:dec r27 ;xy
	brne y1Loop ;(2y-1)(x)
	dec r26     ;x
	brne x1Loop ;(2x-1)
   ret         ; 4
;********************** FIN archivo ************************************************************************************

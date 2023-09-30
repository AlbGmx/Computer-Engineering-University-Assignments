;**************** Algoritmo PresentarBits ********************
;Consideraciones:
;El bit PE1 ya está programado como salida y se le ha escrito un 1 lógico
;inicio:
;Paso 1: Poner en bajo (0 lógico) a PE1.
;Paso 2: Esperar un retardo de 103uS.
;Paso 3: Pasar el bit LSB (menos significativo) de R24 a PE1.
;Paso 4: Esperar un retardo de 103uS.
;Paso 5: Hacer corrimiento a la derecha a R24.
;Paso 6: Si no es el último bit ir al paso 3 de lo contrario continuar
;Nota: El último bit es cuando el MSB original ha llegado al LSB
;Paso 7: Poner PE1 alto (1 lógico). Nota: se deja como estaba al inicio
;Paso 8: Esperar un retardo de 103uS.
;fin:

; **** incluir en la inicialización del archivo Prac3.asm

			sbi DDRE,PE1 ; Programa PE1 como salida
			sbi PORTE,PE1 ; Escribir 1 en PE1
			clr r16 ;
			sts UCSR0B,r16 ;
;********************** Ciclo Principal *********************************
next: 		sbi PORTB,7 ; Escribir 1 en PB7
			rcall miRetardo ; Esperar X mS
			cbi PORTB,7 ; Escribir 0 en PB7
			rcall miRetardo ; Esperar X mS

;****** prueba de PresentarBits *************
			ldi r24,0x55
			rcall PresentarBits
			ldi r24,0x41
			rcall PresentarBits
			ldi r24,0x42
			rcall PresentarBits
			ldi r24,0x43
			rcall PresentarBits
			rjmp next

;********************** FIN archivo **********************************
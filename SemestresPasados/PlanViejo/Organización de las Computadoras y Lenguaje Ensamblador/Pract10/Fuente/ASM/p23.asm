MODEL small
.STACK 100h
        ;----- Insert INCLUDE "filename" directives here
        ;----- Insert EQU and = equates here
       LOCALS
       
.DATA
         string db 10,13,'Cadena apuntada por BX',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)

			mov ax,8Ch		;Valor de donde sera cargada la interrupcion
			lea bx,Int23	;Desplazamiento de la RSI
			mov dx,cs		;Segmento, la RSI se encuentra en el segmento de codigo
			call putInt


			mov ah,1	;Selecciona la interrupcion 1
			mov al,'$'	;Pone el char $ en al
			int 23h		;Llama la interrupcion 23 (la creada)

			lea bx,string	;Apunta bx al string
			mov ah,2		;Selecciona la interrupcion 1
			int 23h		   	;Llama la interrupcion 23 
			
			mov ah,04ch ; fin de programa
			mov al,0
			int 21h
			ret
Principal   ENDP
; --- procedimientos ----;
;***************************************************
putInt 	    PROC
			push ax
			push di
			push es
			
			mov di, ax		;Copiamos el valor de ax a un registro base o indice
            mov ax,0
            mov es,ax 	;Las interrupciones se encuentran desde 0 a 3FF;
			CLI			;Desactiva interrupciones 
			mov word ptr es:[di], offset int23		;Se pone la direccion de la interrupcion en el vector 
			mov word ptr es:[di+2], dx				;Indicamos en donde buscar el codigo
			STI 		;Vuelve a activarlas
			pop es 
			pop ax
			pop si
			ret
putInt 	    ENDP
;***************************************************
Int23       PROC FAR
			push ax
			push dx
			push bx
			  
			cmp ah,1		;Servicio 1
			je @@putchar
			cmp ah,2		;Servicio 2
			je @@puts
			jmp @@end
				
@@putchar:	mov ah,0Eh	;Selecciona el servicio 0Eh
			int 10h		;llama la interrupción para imprimir char
			jmp @@end
				
@@puts:	   	mov ah,0Eh	;Selecciona el servicio 0Eh
@@loop:	   	mov al,[bx]	;Obtiene el char
			cmp al,0	;Si es 0, deja de imprimir
			je @@end
			int 10h		;si no es 0, imprime
			inc bx		;aumenta para siguiente char
			jmp @@loop
				
@@end:	   	pop bx
			pop dx
			pop ax
			iret
Int23       ENDP
        END
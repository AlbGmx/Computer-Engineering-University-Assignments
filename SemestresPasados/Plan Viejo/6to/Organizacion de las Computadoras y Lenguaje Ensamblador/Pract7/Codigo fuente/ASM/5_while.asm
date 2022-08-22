MODEL small
.STACK 100h
INCLUDE procs.inc
LOCALS
.DATA
    ask db 'Desea imprimir el mensaje? (S/N): ',0
    askAgain db 'Desea volver a imprimir el mensaje? (S/N): ',0
    message db 'Este es un mensaje...',0
.CODE
;-----   Insert program, subrutine call, etc., here
Principal  	PROC
			mov ax,@data 	;Inicializar DS al la direccion
			mov ds,ax     	; del segmento de datos (.DATA)
            mov bl,4Eh     ;Valor ascii del char 'n'
			call clrscr
	   	    call println   ;Imprime un salto de linea
	      	mov  dx,offset ask   
			call puts
            call getchar
            mov cl,al
            call println
@@While:    cmp cl,bl      ;While
            JE @@EndWhile
            JMP @@StartWhile
@@StartWhile:
	      	mov  dx,offset message   
			call puts      
		    call println   ;Imprime un salto de linea
	       	mov  dx,offset askAgain   
			call puts
            call getchar
            mov cl,al
            call println
            jmp @@While

@@EndWhile: mov ah,04ch	   ; fin de programa
			mov al,0       ;
			int 21h        ; 
Principal   ENDP

println     PROC ; Funcion para imprimir un salto de linea
            push ax        ;push para guardar su valor en la pila
            mov al,10      ;Salto de línea y
            call putchar
            mov al,13      ;Retorno de carro
            call putchar
            pop ax     ;pop para obtener el valor del registro antes de modificar
            ret
println     ENDP; < -- Indica a TASM el fin del procedimiento
        END

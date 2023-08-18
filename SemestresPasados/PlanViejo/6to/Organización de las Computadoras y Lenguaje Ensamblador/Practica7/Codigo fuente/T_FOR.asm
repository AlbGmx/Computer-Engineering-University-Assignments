MODEL small
   .STACK 100h
 INCLUDE procs.inc
      LOCALS
   .DATA
      ask   db  'Cuantas veces desea imprimir el mensaje(0-9)?: ',0
      xcptn   db  'Por favor, seleccionar un numero valido',0
      message   db  'Mensaje...',0
    .CODE
    ;-----   Insert program, subrutine call, etc., here
    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)
            mov bl,30h
				call clrscr

				mov  dx,offset ask   
				call puts
            call getchar
            mov cl,al
            cmp cl,3Fh
            JG @@Exception
@@StartFOR: call println
            cmp cl,bl
            JE @@EndFor
            dec cl
            mov dx,offset message
            call puts
            JMP @@StartFOR

@@Exception:call println   ;Imprime un salto de linea
	         mov dx,offset xcptn
            call puts

@@EndFor:   mov ah,04ch	   ; fin de programa
				mov al,0       ;
				int 21h        ; 
                ENDP

println PROC ; Funcion para indicar un salto de linea
                           ;Debido que la función modifica el registro A se hace
            push ax        ;push para guardar su valor en la pila
            mov al,10      ;Salto de línea y
            call putchar
            mov al,13      ;Retorno de carro
            call putchar
            pop ax     ;pop para obtener el valor del registro antes de modificar
            ret
         ENDP; < -- Indica a TASM el fin del procedimiento
         END
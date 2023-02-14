MODEL small
   .STACK 100h
 
 INCLUDE procs.inc
       LOCALS
   .DATA
   message db 'Ingresa un digito: ',0
   .CODE
    ;-----   Insert program, subrutine call, etc., here

    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)

@@loop:
            call putNewline
            mov dx,offset message
            call puts
            call getchar
            call isDigit
            cmp bl,0h
            je @@endProgram
            jmp @@loop  

@@endProgram:
				mov ah,04ch	     ; fin de programa
				mov al,0             ;
				int 21h              ; 

                ENDP

putNewline PROC   ;Funcion  para imprimir un salto de linea
            push ax
            mov al, 0Ah    ;Salto de linea
            call putchar
            mov al, 0Dh    ;Retorno de carro
            call putchar
            pop ax
            ret
         ENDP

isDigit PROC ; < -- Indica a TASM el inicio del un procedimiento
            cmp al,'9' 
            jg @@exception
            cmp al,'0' 
            jl @@exception
            mov bl,1h
            jmp @@endCheck
@@exception:
            mov bl,0h
@@endCheck:
            ret    
       ENDP; < -- Indica a TASM el fin del procedimiento

         END
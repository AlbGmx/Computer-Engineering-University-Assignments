MODEL small
   .STACK 100h

   ;----- Insert INCLUDE "filename" directives here
   ;----- Insert EQU and = equates here

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
            mov di,offset message
            call putStr
            call getChar
            call isDigit
            cmp bl,0h
            je @@endProgram
            jmp @@loop  

@@endProgram:
				mov ah,04ch	     ; fin de programa
				mov al,0             ;
				int 21h              ; 

                ENDP
putStr   PROC      ;Funcion para imprimir un string
            push ax        ;Guarda registros a modificar
            push di
@@putStr:         
            mov al,[di]    ;Obtiene el valor de la direccion di y la guarda en al
            cmp al,0h      ;Si es caracter de terminacion
            je @@endputStr ;  Dejar de imprimir 
            mov ah,0Eh     ;Selecciona el servicio 0Eh
            int 10h        ;Llama la interrupcion 10h
            inc di         ;decrementa di
            jmp @@putStr    
@@endputStr:
            pop di         ;Recupera registros modificados
            pop ax
            ret
         ENDP

putNewline PROC   ;Funcion  para imprimir un salto de linea
            push ax
            mov al, 0Ah    ;Salto de linea
            call putChar
            mov al, 0Dh    ;Retorno de carro
            call putChar
            pop ax
            ret
         ENDP

putChar  PROC     ;Funcion para imprimir un char almacenado en al
            push ax     ;Guarda el valor del registro a modificar
            mov ah,0Eh  ;Selecciona el servicio 0Eh
            int 10h     ;Llama la interrupcion 10h
            pop ax      ;Recupera registro 
            ret
         ENDP

getChar  PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
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
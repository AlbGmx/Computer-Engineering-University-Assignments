MODEL small
   .STACK 100h

   ;----- Insert INCLUDE "filename" directives here
   ;----- Insert EQU and = equates here
 
      LOCALS

   .DATA
      ask db 'Ingrese un digito en hexadecimal (0-F): ',0
      result db 'Digito ingresado en decimal: ',0
      xceptn  db  'Digito ingresado no valido...',0
      endASK   db  'Presione cualquier tecla para salir...',0
      
   .CODE
    ;-----   Insert program, subrutine call, etc., here

Principal  PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)

            mov di,offset ask
            call putStr
            call getChar
            call putNewline

            cmp al,'0'     ;comprueba que sea mayor o igual a 30h (0 en ascii)
            jl @@exception
            cmp al,'F'     ;comprueba que sea menor o igual a 46h (F en ascii)
            jg @@exception
            cmp al,3Ah     ;Si es menor que 3Ah se salta las pruebas porque el numero esta entre (0-9)
            jl @@endCheck
            
            cmp al,'A'     ;Si es menor que 'A'
            jl @@exception ;Manda excepcion

            sub al,11h     ;Se le resta 11h para indicar su valor (F-11=5)
            push ax        ;Se guarda el valor de AX
            mov di,offset result 
            call putStr    ;Mensaje de respuesta
            mov al,'1'     ;Se imprime el '1'
            call putChar   
            pop ax         ;Se recupera el valor de ax
            call putChar   ;Y se imprime
            jmp @@endProgram
@@endCheck: 
            ;Si el valor es un numero, se imprime directamente
            mov di,offset result
            call putStr
            call putChar
            jmp @@endProgram
@@exception:
            mov di,offset xceptn
            call putStr
@@endProgram:
            call putNewline
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

getChar  PROC     ;Funcion para leer un char y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
         ENDP
      END
MODEL small
   .STACK 100h
 INCLUDE procs.inc
       LOCALS
   .DATA 
      ask db 'Ingrese un digito en hexadecimal (0-F): ',0
      result db 'Digito ingresado en decimal: ',0
      xceptn  db  'Digito ingresado no valido...',0
      
   .CODE
    ;-----   Insert program, subrutine call, etc., here

Principal  PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)

            mov dx,offset ask
            call puts
            call getchar
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
            mov dx,offset result 
            call puts    ;Mensaje de respuesta
            mov al,'1'     ;Se imprime el '1'
            call putchar   
            pop ax         ;Se recupera el valor de ax
            call putchar   ;Y se imprime
            jmp @@endProgram
@@endCheck: 
            ;Si el valor es un numero, se imprime directamente
            mov dx,offset result
            call puts
            call putchar
            jmp @@endProgram
@@exception:
            mov dx,offset xceptn
            call puts
@@endProgram:
            call putNewline
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

         ENDP
      END
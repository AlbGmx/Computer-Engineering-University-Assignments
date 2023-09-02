MODEL small
   .STACK 100h

       LOCALS

   .DATA
      buffer db 4,?,4 dup(0)
      ask db 'Ingrese un numero (0-100): ',10,13,0
      result db 'Numero ingresado: ',0
      xceptn  db  10,13,'Numero ingresado no valido...',0
      newln  db  10,13,0
     
   .CODE
    ;-----   Insert program, subrutine call, etc., here

    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)

            mov di,offset ask
            call putStr
				
            mov dx, offset buffer
		      mov ah, 0Ah
		      int 21h
            mov bl,buffer[1]     ;Despues de utilizar la interrupcion 21 es necesario 
      		mov buffer[bx+2], 0  ;agregar el caracter de terminacion manualmente
                                 ;  El tamaño del string se encuentra en la segunda posicion
            mov al, buffer[2]
            cmp buffer[2],'9' ;Si el primer char es mayor que 39Ah (ascii de 9)
            jg @@exception    ;manda error
            cmp buffer[2],'0' ;Si el primer char es menor que 30h (ascii de 0)
            jl @@exception    ;manda error
            cmp buffer[3],0h  ;Si el segundo char es 0 
            je @@continue     ;salta a continuar sin hacer mas pruebas
            cmp buffer[3],'9' ;hace las mismas comprobaciones (0<char>9) para el 2do char
            jg @@exception
            cmp buffer[3],'0'
            jl @@exception
            cmp buffer[4],0h  ;Si el tercer char es 0 
            je @@continue     ;salta a continuar sin hacer mas pruebas
            cmp buffer[4],'9' ;hace las mismas comprobaciones (0<char>9) para el 3er char
            jg @@exception
            cmp buffer[4],'0'
            jl @@exception
@@continue:
            mov di,offset result
            call putStr

            mov di,offset buffer+2  ;Debido a que la interrupcion 21/0Ah utiliza los primeros dos bytes  
            call putStr             ;para guardar informacion es necesario desplazar el resultado 2 posiciones                
            jmp @@endProgram
@@exception:
            mov di,offset xceptn
            call putStr
@@endProgram:
            mov di,offset newln
            call putStr
				mov ah,04ch	     ; fin de programa
				mov al,0             ;
				int 21h              ; 
                ENDP

putStr   PROC      ;Funcion para imprimir un string
            push ax        ;Guarda registros a modificar
            push di
@@putStr:         
            mov al,[di]    ;Bbtiene el valor de la direccion di y la guarda en al
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
      END
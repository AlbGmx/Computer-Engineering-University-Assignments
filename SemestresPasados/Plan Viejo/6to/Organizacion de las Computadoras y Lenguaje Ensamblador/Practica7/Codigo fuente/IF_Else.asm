MODEL small
   .STACK 100h
 INCLUDE procs.inc
       LOCALS
   .DATA
      ask   db  'Presione la tecla A mayuscula: ',0
      IfThen   db  'Ha presionado la tecla A mayuscula',0
      IfThenElse   db  'No ha presionado la tecla A mayuscula',0
      endASK   db  'Presione cualquier tecla para salir...',0
   .CODE
    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)
            mov bl,41h     ;Introduce el valor ascii hex de la A mayuscula
				call clrscr    
				mov  dx,offset ask   
				call puts
				
            call getchar   ;Espera una tecla del usuario
            call println   ;Imprime un salto de linea

            cmp al,bl      ;Compara el valor introducido con bl
            JE @@IfThen    ;Si son iguales imprime un mensaje
            JMP @@Else     ;Si no son iguales, imprime otro mensaje
@@IfThen:   mov dx,offset IfThen
            call puts  
            call println   ;Imprime un salto de linea
            JMP @@EndIF
@@Else:     mov dx,offset IfThenElse
            call puts  
@@EndIF:  	mov ah,04ch	     ; fin de programa
				mov al,0             ;
				int 21h              ; 
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
MODEL small
.STACK 100h
INCLUDE procs.inc
LOCALS
.DATA
    ask db 'Presione la tecla A mayuscula: ',0
    messageIF db 'Ha presionado la tecla A mayuscula',0
    messageIFElse db 'No ha presionado la tecla A mayuscula',0
    endASK db 'Presione cualquier tecla para salir...',0
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
            JNE @@Else    ;Si son iguales imprime un mensaje
@@messageIF:   
            mov dx,offset messageIF
            JMP @@EndIF
@@Else:     mov dx,offset messageIFElse
            
@@EndIF:  	call puts  
            mov ah,04ch	     ; fin de programa
			mov al,0             ;
			int 21h              ; 
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
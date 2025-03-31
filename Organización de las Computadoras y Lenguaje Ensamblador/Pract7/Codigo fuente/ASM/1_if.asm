MODEL small
.STACK 100h
INCLUDE procs.inc
LOCALS
.DATA
    ask   db  'Presione la tecla A mayuscula: ',0
    message   db  'Ha presionado la tecla A mayuscula',0  
.CODE
Principal   PROC
            mov ax,@data   ;Inicializar DS al la dirección
            mov ds,ax      ; del segmento de datos (.DATA)
            mov bl,41h     ;Introduce el valor ascii hex de la A mayúscula
            call clrscr

            mov  dx,offset ask   
            call puts
   
            call getchar   ;Espera una tecla del usuario
            call println   ;Imprime un salto de línea

            cmp al,bl      ;Compara el valor introducido con bl
            JNE @@EndIF    ;Si no son iguales se sale
@@IfThen:   mov dx,offset message

            call puts  
            call println   ;Imprime un salto de línea

@@EndIF:    mov ah,04ch      ; fin de programa
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
MODEL small
   .STACK 100h
 INCLUDE procs.inc
       LOCALS
   .DATA 
   .CODE
    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)
            mov cx,0h
            mov al,2Ah
            mov bh,5h
            mov bl,1h
 @@for1: 
            cmp ch,bh
            je @@changeSign;Cambia el signo de bl
            add ch,bl      
            mov cl,1h      ;Reinicia el valor de cl en 1
            call putNewline
 @@for2:
            cmp ch,0h
            je @@endProgram
            call putchar
            cmp cl,ch      ;Imprime el valor CH veces
            je @@for1
            inc cl
            jmp @@for2

@@changeSign:
            cmp ch,0h   ;Si CH es 0 
            je @@endProgram;Sale del programa
            sub bl,2    ;Se hace negativo
            mov bh,0h   ;Se hace 0
            jmp @@for1

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
      END
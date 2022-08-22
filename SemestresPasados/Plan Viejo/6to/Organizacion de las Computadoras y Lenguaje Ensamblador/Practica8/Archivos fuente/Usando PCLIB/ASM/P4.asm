MODEL small
   .STACK 100h
 INCLUDE procs.inc
       LOCALS
   .DATA 
   .CODE
    ;-----   Insert program, subrutine call, etc., here

    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)
            mov cx,0h
            mov al,2Ah
 @@for1:
            cmp ch,5h   ;Cuando CH sea 5 
            je @@endProgram   ;Sale del programa
            inc ch      
            xor cl,cl   ;Resetea el valor de cl
            call putNewline
 @@for2:
            call putchar
            cmp cl,4h   ;Imprime el char 5 veces
            je @@for1   
            inc cl
            jmp @@for2

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
      END
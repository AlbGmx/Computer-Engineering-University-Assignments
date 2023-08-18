MODEL small
   .STACK 100h
 
 INCLUDE procs.inc
       LOCALS
   .DATA
      endASK   db  'Presione cualquier tecla para salir...',0
      hello   db  'Hola Mundo',0

   .CODE

    Principal  	PROC
				mov ax,@data 	   ;Inicializar DS al la direccion
				mov ds,ax     	   ; del segmento de datos (.DATA)
            mov dx, offset hello
            call puts
				mov ah,04ch	     ; fin de programa
				mov al,0         
				int 21h          
                ENDP
         END
MODEL small
   .STACK 100h
 
       LOCALS

   .DATA
      endASK   db  'Presione cualquier tecla para salir...',0
      helloBIOS   db  'Hola Mundo, impreso con los servicios BIOS ',10,13,0
      helloDOS   db  'Hola Mundo, impreso con los servicios DOS ',10,13,0

   .CODE

    Principal  	PROC
				mov ax,@data 	   ;Inicializar DS al la direccion
				mov ds,ax     	   ; del segmento de datos (.DATA)

            mov di, offset helloBIOS
@@printBIOS:                  ;Impresion utilizando el servicio 0Eh de la interrupcion 10h de BIOS  
            mov al,[di]
            cmp al,0h         ;Cuando se encuentre el caracter de terminacion
            je @@continue     ;Termina de imprimir 
            mov ah,0Eh        ;Servicio 0Eh
            int 10h           ;Interrupion 10h
            inc di            ;Aumenta el indice de datos
            jmp @@printBIOS   ;Regresa al comienzo

@@continue:
            mov di, offset helloDOS
@@printDOS:                   ;Impresion utilizando el servicio 02h de la interrupcion 21h de DOS  
            mov dl,[di]
            cmp dl,0h         ;Cuando se encuentre el caracter de termiacion
            je @@endPrinting  ;Termina de imprimir
            mov ah,02h        ;Servicio 02h
            int 21h           ;Interrupcion 21h
            inc di            ;Aumenta el indice de datos
            jmp @@printDOS    ;Regresa al comienzo
@@endPrinting:
				mov ah,04ch	     ; fin de programa
				mov al,0         
				int 21h          
                ENDP

         END
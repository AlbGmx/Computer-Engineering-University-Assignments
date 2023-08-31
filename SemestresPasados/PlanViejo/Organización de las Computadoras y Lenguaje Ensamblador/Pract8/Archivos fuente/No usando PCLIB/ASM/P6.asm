MODEL small
   .STACK 100h

   ;----- Insert INCLUDE "filename" directives here
   ;----- Insert EQU and = equates here
 
       LOCALS

   .DATA
   message db 'Ingresa las letras a ordenar: ',0
   xceptn  db 'Ambas letras deben ser mayusculas...',0
   sorted  db 'Letras ordenadas:  ',0,10,13
   charA db 0
   charB db 0

   .CODE
    ;-----   Insert program, subrutine call, etc., here

    Principal  	PROC
		mov ax,@data 	;Inicializar DS al la direccion
		mov ds,ax     	; del segmento de datos (.DATA)

            mov di,offset message
            call putStr

            call getChar   ;Lee un valor y lo guarda en charA
            mov charA,al
            call getChar   ;Lee un valor y lo guarda en charB
            mov charB,al
            call isAplha   ;Compara que charB sea mayuscula
            cmp bl,01h
            jne @@exception
            mov al,charA   ;Compara que charA sea mayuscula            
            call isAplha
            cmp bl,01h
            jne @@exception

            call putNewline
            mov di,offset sorted
            call putStr

            cmp al,charB
            jl @@bGreater  
            mov al,charB   ;Si charA es mas grande
            call putChar   ;Imprime primero B y
            mov al,charA   ;luego A
            call putChar
            jmp @@endProgram

@@bGreater: call putChar   ;Si B es mas grande, imprime A y luego B
            mov al,charB
            call putChar
            jmp @@endProgram

@@exception:call putNewline
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

getChar  PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
         ENDP
               ;Comprueba que al se encuentre dentro del alfabeto    
isAplha  PROC  ;Si no esta dentro devuelve 02h en bl, si es mayuscula 01h, si es minuscula 00h
      push ax
      ;Para que este en el alfabeto mayuscula debe cumplirse ('A' >= x <= 'Z')
      cmp al,'A' 
      jl @@exception 
      cmp al,'Z' 
      jle @@isUpper
      ;Para que este en el alfabeto minuscula debe cumplirse ('a' >= x <= 'z')
      cmp al,'a' 
      jl @@exception
      cmp al,'z' 
      jl @@isLower  
      ;Si no se cumple ningun caso anterior, no esta en el alfabeto
      jmp @@exception 
@@exception:
      mov bl,2h
      jmp @@endCheck
@@isUpper:
      mov bl,1h
      jmp @@endCheck
@@isLower:
      mov bl,0h
@@endCheck:
      pop ax   ;Recupera registro
      ret    
         ENDP
   END
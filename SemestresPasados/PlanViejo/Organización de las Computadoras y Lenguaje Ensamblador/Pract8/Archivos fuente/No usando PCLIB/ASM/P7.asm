MODEL small
   .STACK 100h

   ;----- Insert INCLUDE "filename" directives here
   ;----- Insert EQU and = equates here

       LOCALS

   .DATA
   message db 'Ingresa dos letras: ',0
   xceptn  db 'Ambas letras deben estar en el alfabeto (A-z)...',0
   xceptn2  db 'No pueden ser ambas mayusculas o minusculas',0
   message1  db 'La primera letra ',0
   message2  db 'y la segunda letra ',0
   upper db ' es mayuscula ',0
   lower db ' es minuscula ',0
   charA db 0
   charB db 0

   .CODE
    ;-----   Insert program, subrutine call, etc., here

    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)

            mov di,offset message
            call putStr

            call getChar   ;Lee un valor para charA 
            mov charA,al
            call getChar   ;Lee un valor para charB
            mov charB,al

            call putNewline

            mov al,charA
            call isAplha   ;Revisa si esta en el alfabeto
            cmp bl,02h     ;Si no esta en el alfabeto
            je @@exception ;Manda una excepcion
            mov bh,bl      ;Copia bl a bh

            mov al,charB
            call isAplha   ;Revisa si esta en el alfabeto
            cmp bl,bh      ;Si ambas letras son mayusculas o minusculas
            je @@exception2
            cmp bl,02h     ;Si no esta en el alfabeto
            je @@exception ;Manda una excepcion
            
            mov cl,0h      ;Reinicia el contador
            mov di,offset message1
            call putStr
            mov al,charA   ;Imprime charA
            call putchar
            cmp bh,01h        ;Si es mayuscula
            je @@printupper   ;Imprime mensaje mayuscula
            jmp @@printlower  ;Imprime mensaje minuscula

@@second:                  
            ;Ahora imprime charB     
            mov di,offset message2
            call putStr
            mov al,charB
            call putchar
            cmp bl,01h
            je @@printupper
            jg @@exception
            jmp @@printlower

@@printupper:  ;Imprime diciendo que es mayuscula
            mov di,offset upper
            call putStr
            inc cl
            cmp cl,1h   
            je @@second
            jmp @@endProgram
            
@@printlower:  ;Imprime diciendo que es minuscula
            mov di,offset lower
            call putStr
            inc cl
            cmp cl,1h
            je @@second
            jmp @@endProgram
            
@@exception:
            call putNewline
            mov di,offset xceptn
            call putStr
            jmp @@endProgram
@@exception2:
            mov di,offset xceptn2
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
      jle @@isLower  
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
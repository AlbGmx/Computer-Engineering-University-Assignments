MODEL small
   .STACK 100h
 
 INCLUDE procs.inc
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

            mov dx,offset message
            call puts

            call getchar   ;Lee un valor para charA 
            mov charA,al
            call getchar   ;Lee un valor para charB
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
            mov dx,offset message1
            call puts
            mov al,charA   ;Imprime charA
            call putchar
            cmp bh,01h        ;Si es mayuscula
            je @@printupper   ;Imprime mensaje mayuscula
            jmp @@printlower  ;Imprime mensaje minuscula

@@second:                  
            ;Ahora imprime charB     
            mov dx,offset message2
            call puts
            mov al,charB
            call putchar
            cmp bl,01h
            je @@printupper
            jg @@exception
            jmp @@printlower

@@printupper:  ;Imprime diciendo que es mayuscula
            mov dx,offset upper
            call puts
            inc cl
            cmp cl,1h   
            je @@second
            jmp @@endProgram
            
@@printlower:  ;Imprime diciendo que es minuscula
            mov dx,offset lower
            call puts
            inc cl
            cmp cl,1h
            je @@second
            jmp @@endProgram
            
@@exception:
            call putNewline
            mov dx,offset xceptn
            call puts
            jmp  @@endProgram
@@exception2:
            mov dx,offset xceptn2
            call puts

@@endProgram:
            call putNewline
		mov ah,04ch	     ; fin de programa
		mov al,0             ;
		int 21h              ; 

                ENDP

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

               ;Comprueba que al se encuentre dentro del alfabeto    
isAplha  PROC  ;Si no esta dentro devuelve 02h en bl, si es mayuscula 01h, si es minuscula 00h
      push ax
      ;Para que este en el alfabeto mayuscula debe cumplirse ('A' >= x <= 'Z')
      cmp al,'A' 
      jl @@exception 
      cmp al,'Z' 
      jl @@isUpper
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
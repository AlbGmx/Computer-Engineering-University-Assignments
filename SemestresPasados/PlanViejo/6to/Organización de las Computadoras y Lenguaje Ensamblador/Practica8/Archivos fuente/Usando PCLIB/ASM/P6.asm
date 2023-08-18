MODEL small
   .STACK 100h
 INCLUDE procs.inc
       LOCALS
   .DATA 
   message db 'Ingresa las letras a ordenar: ',0
   xceptn  db 'Ambas letras deben ser mayusculas...',0
   sorted  db 'Letras ordenadas:  ',0
   charA db 0
   charB db 0

   .CODE
    ;-----   Insert program, subrutine call, etc., here

    Principal  	PROC
		mov ax,@data 	;Inicializar DS al la direccion
		mov ds,ax     	; del segmento de datos (.DATA)

            mov dx,offset message
            call puts

            call getchar   ;Lee un valor y lo guarda en charA
            mov charA,al
            call getchar   ;Lee un valor y lo guarda en charB
            mov charB,al
            call isAplha   ;Compara que charB sea mayuscula
            cmp bl,01h
            jne @@exception
            mov al,charA   ;Compara que charA sea mayuscula            
            call isAplha
            cmp bl,01h
            jne @@exception

            call putNewline
            mov dx,offset sorted
            call puts

            cmp al,charB
            jl @@bGreater  
            mov al,charB   ;Si charA es mas grande
            call putchar   ;Imprime primero B y
            mov al,charA   ;luego A
            call putchar
            jmp @@endProgram

@@bGreater: call putchar   ;Si B es mas grande, imprime A y luego B
            mov al,charB
            call putchar
            jmp @@endProgram

@@exception:call putNewline
            mov dx,offset xceptn
            call puts
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
MODEL small
.STACK 100h
LOCALS       
.DATA
    ask db 10,13,'Introduzca la palabra: ',0
    pal db 10,13,'No es un palindromo',10,13,0
    noPal db 10,13,'Si es un palindromo',10,13,0
    palWord db 21 dup(0)
    revPalWord db 21 dup(0) 
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)
            lea di,ask
            call putStr
            lea di,palWord
            call getAlphaStr
            lea di,palWord
            lea si,revPalWord
@@prepareDI:
            cmp byte ptr [di],0
            je @@invertStr
            inc di
            jmp @@prepareDI
@@invertStr:
            dec di
            cmp di,offset palWord-1
            je @@endRev
            mov al,[di]
            mov [si],al
            inc si
            jmp @@invertStr
@@endStr:   mov byte ptr [si],0            
@@endRev:   lea si,revPalWord
            lea di,palWord
            call palindrome
            cmp bl,1
            je @@notPal
            lea di,pal
            jmp @@print
@@notPal:   lea di,noPal
@@print:    call putStr
@@end:      mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
Principal   ENDP
; --- procedimientos ----;
palindrome  PROC
            push ax
            push di
            push si
            mov bl,0    ;Empezamos suponiendo que no son palindromos
@@compareStr: 
            mov al,[di]
            cmp al,0
            je @@isPal
            mov al,[si]
            cmp al,0
            je @@isPal
            cmp [di],al
            jne @@end
            inc si
            inc di
            jmp @@compareStr
@@isPal:    mov bl,1   
@@end:      pop si
            pop di
            pop ax
            ret 
palindrome  ENDP
;***************************************************
getAlphaStr PROC
            push ax
            push cx
            push di
            mov cx,20
@@while:    call getChar
            call isAplha
            cmp bl,02
            je @@end2
            mov [di],al
            inc di
            dec cx
            cmp cx,0
            je @@end
            jmp @@while
@@end2:     inc di   
@@end:      mov byte ptr [di],0
            pop di
            pop cx
            pop ax
            ret
getAlphaStr ENDP              ;El tamaño del string se encuentra en la segunda posicion
;***************************************************
putChar     PROC     ;Funcion para imprimir un char almacenado en al
            push ax     ;Guarda el valor del registro a modificar
            mov ah,0Eh  ;Selecciona el servicio 0Eh
            int 10h     ;Llama la interrupcion 10h
            pop ax      ;Recupera registro 
            ret
putChar     ENDP
;***************************************************
isAplha     PROC  ;Si no esta dentro devuelve 02h en bl, si es mayuscula 01h, si es minuscula 00h
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
@@exception:mov bl,2h
            jmp @@endCheck
@@isUpper:  mov bl,1h
            jmp @@endCheck
@@isLower:  mov bl,0h
@@endCheck: pop ax   ;Recupera registro
            ret    
isAplha     ENDP
;***************************************************
putStr      PROC      ;Funcion para imprimir un string
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
putStr      ENDP
;****************************************************   
putNewline  PROC   ;Funcion  para imprimir un salto de linea
            push ax
            mov al, 0Ah    ;Salto de linea
            call putChar
            mov al, 0Dh    ;Retorno de carro
            call putChar
            pop ax
            ret
putNewline  ENDP 
;****************************************************   
getChar     PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
getChar     ENDP
        END 
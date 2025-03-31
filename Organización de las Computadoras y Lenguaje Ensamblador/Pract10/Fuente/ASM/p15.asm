MODEL small
.STACK 100h
LOCALS       
.DATA
    ask db 10,13,'Introduzca la palabra: ',0
    palabra db 27 dup(0)
    alpha db 27 dup(0)    
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)
            lea di,ask
            call putStr
            lea di,palabra
            call getAlphaStr
            lea si,alpha
            call count
            call putNewline
            mov bx,0
@@while:    cmp byte ptr si[bx],0
            je @@continue
@@printCount:
            mov al,bl
            add al,'A'
            call putChar
            mov al,'='
            call putChar
            mov al,si[bx]
            call printDec
@@continue: inc bx
            cmp bx,26
            jb @@while

@@end:      mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
Principal   ENDP
; --- procedimientos ----;
count       PROC
            push ax
            push bx
            push di     
            push si
@@countLetters: 
            mov al,[di]
            call isAplha
            cmp bl,2
            je @@end
            cmp bl,1
            je @@upper2Lower
            jmp @@count
@@upper2Lower:
            add al,' '
            mov [di],al
@@count:    
            mov bh,0
            mov bl,[di]
            sub bl,'a'
            mov ah,0
            add byte ptr si[bx],01
            inc di
            jmp @@countLetters
@@end:      pop si
            pop di
            pop bx
            pop ax
            ret 
count       ENDP
;***************************************************
printDec    PROC                ;Modificado para imprimir todo AX en vez de solo AL
            push ax             ; salvar registro a utilizar
            push bx
            push cx
            push dx
            mov cx,3            ; inicializar conteo a 3 (cent-dec-unidades)
            mov bx,100        ; iniciar con centenas
            mov ah,0
@@nxt:      mov dx,0            ; asegurar DX=0 para usar div reg16
            div bx              ; dividir DX:AX entre BX
            add al,'0'          ; convertir cociente a ASCII
            call putChar        ; desplegar digito en pantalla
            mov ax,dx           ; pasar residuo (DX) a AX
            push ax             ; salvar temporalmente AX
            mov dx,0            ; ajustar divisor para nuevo digito
            mov ax,bx           ; la idea es:
            mov bx,10           ; BX = BX/10
            div bx
            mov bx,ax           ; pasar cociente al BX para nuevo digito
            pop ax              ; recupera AX
            loop @@nxt          ; proximo digito
            mov al,' '
            call putChar
            pop dx
            pop cx
            pop bx
            pop ax
            ret
printDec    ENDP
;***************************************************
getAlphaStr PROC
            push ax
            push cx
            push di
            mov cx,20
@@while:    
            call getChar
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
putChar     ENDP;***************************************************
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
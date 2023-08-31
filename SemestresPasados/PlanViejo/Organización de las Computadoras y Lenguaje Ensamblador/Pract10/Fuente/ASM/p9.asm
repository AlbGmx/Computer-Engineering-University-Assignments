MODEL small
.STACK 100h
LOCALS 
.DATA
    ask db 10,13,'Serie: ',0
    ans db 10,13,10,13,'Resultado: ',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)

            mov ax,0h
            mov bx,0h

            mov di, offset ask
            call putStr
            mov bx,10           
            call printDecAL
            mov cl,1
            mov al,0
            mov bx,0            
@@while:    mov al,','
            call putChar
            mov al,' '
            call putChar
            mov ax,3
            mul cl
            add bx,ax
            inc cl 
            call printDecAL
            cmp cl,33d
            jle @@while

            mov di, offset ans
            call putStr
            mov ax,bx
            call printDecAX
            call putNewline
            mov ah,04ch         ; fin de programa
            mov al,0             ;
            int 21h              ; 

@@end:      call putNewline
            mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
Principal   ENDP
; --- procedimientos ----;
printDecAL  PROC                ;Modificado para imprimir todo AX en vez de solo AL
            push ax             ; salvar registro a utilizar
            push bx
            push cx
            push dx
            mov cx,2            ; inicializar conteo a 2 (cent-dec-unidades)
            mov bx,10          ; iniciar con centenas
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
            pop dx
            pop cx
            pop bx
            pop ax
            ret
printDecAL  ENDP
;***************************************************  
printDecAX  PROC                ;Modificado para imprimir todo AX en vez de solo AL
            push ax             ; salvar registro a utilizar
            push bx
            push cx
            push dx            
            mov cx,4            ; inicializar conteo a 4 (unidades de mil-cent-dec-unidades)
            mov bx,1000         ; iniciar con unid de millar
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
            pop dx
            pop cx
            pop bx
            pop ax
            ret
printDecAX  ENDP
;***************************************************  
putChar     PROC     ;Funcion para imprimir un char almacenado en al
            push ax     ;Guarda el valor del registro a modificar
            mov ah,0Eh  ;Selecciona el servicio 0Eh
            int 10h     ;Llama la interrupcion 10h
            pop ax      ;Recupera registro 
            ret
putChar     ENDP
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
;***************************************************
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
getCh       PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,8h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
getCh       ENDP
        END   
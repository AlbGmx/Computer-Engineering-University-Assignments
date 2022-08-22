MODEL small
.STACK 100h
LOCALS
.DATA
    array db 2,4,6,8,10,12,14,16,18,20
    array_message db 10,13,'Array: ',0
    avg db 10,13,'Promedio: ',0
    maximum db 10,13,'Mayor: ',0
    minimum db 10,13,'Menor: ',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)
        
            mov cx,10
            lea di,array_message
            call putStr
            call printArray

            lea di,avg
            call putStr
            call average
            call printDec

            lea di,minimum
            call putStr
            call min
            call printDec

            lea di,maximum
            call putStr
            call max
            call printDec
            call putNewline
            mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
Principal   ENDP
; --- procedimientos ----;
printArray  PROC
            push bx
            push cx
            mov bx,0
            mov ah,0
@@print:    mov al,array[bx]
            call printDec
            mov al,' '
            call putChar
            inc bx
            loop @@print
            pop cx
            pop bx
            ret
printArray  ENDP
;***************************************************
average     PROC
            push bx
            push dx
            push cx
            mov ax,0
            mov bx,0
@@add:      add al,array[bx]
            inc bx
            loop @@add
            pop cx
            div cl
            pop dx
            pop bx
            ret
average     ENDP
;***************************************************
max         PROC
            push bx
            push dx
            push cx
            mov ax,0
            mov bx,0
@@add:      cmp al,array[bx]
            jae @@incBX
            mov al,array[bx]
@@incBX:    inc bx
            loop @@add
            pop cx
            pop dx
            pop bx
            ret
max         ENDP
;***************************************************
min         PROC
            push bx
            push dx
            push cx
            mov bx,0
            mov ax,0
            mov al,array[bx]
            inc bx
            dec cx
@@add:      cmp al,array[bx]
            jbe @@incBX
            mov al,array[bx]
@@incBX:    inc bx
            loop @@add
            pop cx
            pop dx
            pop bx
            ret
min         ENDP
;***************************************************
printDec    PROC                ;Modificado para imprimir todo AX en vez de solo AL
            push ax             ; salvar registro a utilizar
            push bx
            push cx
            push dx
            mov cx,3            ; inicializar conteo a 5 (decenas de mil-unidades de mil-cent-dec-unidades)
            mov bx,100        ; iniciar con dec de millar
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
printDec    ENDP
;****************************************************       
putChar     PROC     ;Funcion para imprimir un char almacenado en al
            push ax     ;Guarda el valor del registro a modificar
            mov ah,0Eh  ;Selecciona el servicio 0Eh
            int 10h     ;Llama la interrupcion 10h
            pop ax      ;Recupera registro 
            ret
putChar     ENDP
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
        END
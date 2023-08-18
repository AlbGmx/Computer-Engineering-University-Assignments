MODEL small
.STACK 100h
LOCALS
.DATA
    ask db 10,13,'Introduzca el la temperatura en grados : ',0
    answer   db 10,13,'La temperatura en Fahrenheit es ',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)

            mov di,offset ask
            call putStr
            call getInt

            ;Formula F=(9/5)C+32
            ;9/5 = 1.8 redondeado a 2
            mov bx,2
            mul bx      ;2*C
            add ax,32d  ;2*C+32

            mov di,offset answer
            call putStr
            call printDec
            call putNewline

            mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
            ENDP
; --- procedimientos ----;
printDec    PROC                ;Modificado para imprimir todo AX en vez de solo AL
            push ax             ; salvar registro a utilizar
            push bx
            push cx
            push dx
            mov cx,5            ; inicializar conteo a 5 (decenas de mil-unidades de mil-cent-dec-unidades)
            mov bx,10000        ; iniciar con dec de millar
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
            ENDP
;***************************************************
getInt   PROC           ;Obtiene un valor y lo convierte a hexadecimal
         push bx
         push cx
         push dx
         push si
		   mov ax,0
		   mov bx,0
         mov cx,10d
         mov dx,0
         mov si,0
@@next:  call getChar
      	sub al,'0'
      	cmp al,9		
      	ja @@end
         mov ah,0
         push ax     ;Guardamos el valor de ax en la pila
         mov ax,si
         mul cx
         pop dx      ;recuperamos el valor de ax y lo ponemos en dx
         add ax,dx
         mov si,ax
         inc bx
		   jmp @@next
@@end:   mov ax,si
         pop si
         pop dx
         pop cx
         pop bx
         ret
         ENDP
;****************************************************       
putChar  PROC     ;Funcion para imprimir un char almacenado en al
            push ax     ;Guarda el valor del registro a modificar
            mov ah,0Eh  ;Selecciona el servicio 0Eh
            int 10h     ;Llama la interrupcion 10h
            pop ax      ;Recupera registro 
            ret
         ENDP

;***************************************************
putNewline PROC   ;Funcion  para imprimir un salto de linea
            push ax
            mov al, 0Ah    ;Salto de linea
            call putChar
            mov al, 0Dh    ;Retorno de carro
            call putChar
            pop ax
            ret
         ENDP
;***************************************************
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
;****************************************************    
getChar  PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
         ENDP
        END   
       ENDP
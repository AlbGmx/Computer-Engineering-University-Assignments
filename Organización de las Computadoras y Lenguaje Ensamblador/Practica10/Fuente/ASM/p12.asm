MODEL small
.STACK 100h
LOCALS
      
.DATA
    ask db 10,13,'Introduzca el primer numero (max: 255): ',0
    ansSi db 'Si es primo',10,13,0
    ansNo db 'No es primo',10,13,0
    greater db 0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)

            mov si,offset greater

            mov di,offset ask
            call putStr
            call getInt
            mov ah,0
            mov [si], ax
            cmp al,0
            je @@case2
            cmp al,1
            je @@case1

            mov cx,2
            div cl
            inc cl
            cmp ah,0
            je @@case2

@@while: 
            mov ax,[si]
            cmp cl,[si]
            jae @@case1
            div cl
            add cl,2
            cmp ah,0
            je @@case2
            jmp @@while

@@case1:    lea di,ansSi
            jmp @@print
@@case2:    lea di,ansNo

@@print:    call putStr

@@end:      mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
Principal   ENDP
; --- procedimientos ----;
printDec    PROC                
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
getInt      PROC           ;Obtiene un valor y lo convierte a hexadecimal
            push bx
            push dx
            mov bx,0h
            mov dx,0Ah
@@while:    call getChar  
            call isDec
            cmp bl,01  ;Mientras el digito introducido sea un decimal valido
            jne @@end
            sub al,'0'
            mov bl,al   
            mov al,bh
            mul dl
            add al,bl
            mov bh,al
            jmp @@while
@@end:      mov al,bh
            pop dx
            pop bx

getInt      ENDP
;***************************************************
isDec       PROC  ;Revisa que al sea un digito decimal valido (0-9)
            cmp al,'9'            ;Compara que al se encuentre dentro del rango (0-9) 
            jg @@exception
            cmp al,'0' 
            jl @@exception
            mov bl,1h
            jmp @@endCheck
@@exception:
            mov bl,0h           ;En caso de haber un error, resetea bl
@@endCheck: ret    
isDec       ENDP
;****************************************************       
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
;****************************************************    
getChar     PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
getChar     ENDP
        END
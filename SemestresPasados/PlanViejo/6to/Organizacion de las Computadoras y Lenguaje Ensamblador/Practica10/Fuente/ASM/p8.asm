MODEL small
.STACK 100h
LOCALS
.DATA
    ask db 10,13,'Introduzca la serie de numeros: ',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)
            mov di, offset ask
            call putStr

@@while:    call getCh
            call isDec9
            cmp bl,01
            jl @@while
            jg @@end
            call putChar
            jmp @@while 

@@end:      call putNewline
            mov ah,04ch ; fin de programa
            mov al,0
            int 21h
            ret
Principal   ENDP
; --- procedimientos ----;
;***************************************************
isDec9      PROC  ;Revisa que al sea un digito decimal valido (0-9)
            mov bl,1h
            cmp al,'9'            ;Compara que al se encuentre dentro del rango (0-9) 
            jg @@exception
            cmp al,'0' 
            jg @@endCheck
            mov bl,02h
            jmp @@endCheck
@@exception:
            mov bl,0h           ;En caso de haber un error, resetea bl
@@endCheck: ret    
isDec9      ENDP
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
;****************************************************    
getCh       PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,8h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
getCh       ENDP
        END   
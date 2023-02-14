MODEL small
.STACK 100h
LOCALS
    ARGSSIZE EQU 20
.DATA
    args  db ARGSSIZE dup(0)
    arg1  db ARGSSIZE dup(0)
    arg2  db ARGSSIZE dup(0)
    ans db 10,13,'El numero ',0
    ans2 db 'es la suma de los otros dos',10,13,0
    ans3 db 10,13,'Ningun numero es la suma de los otros dos',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal 	PROC
			mov cl, ds:[80] 	; 
			mov dx, 81h		   	; en esta direccion
			call cleanPar		; elimina el espacio y pasa los argumentos a una var

			mov ax,@data ;Inicializar DS al la direccion
			mov ds,ax ; del segmento de datos (.DATA)

			call changeSegment
			call separateArgs
         
            lea di,args
            call text2dec
            lea bx,args
            mov [bx],ax
            call printDec

            lea di,arg1
            call text2dec
            lea si,arg1
            mov [si],ax
            call printDec

            lea di,arg2
            call text2dec
            mov [di],ax
            call printDec

            mov ax,[bx]
            mov ax,[si]
            mov ax,[di]

            mov ax,[bx]
            add ax,[si]
            cmp ax,[di]
            je @@case1

            mov ax,[di]
            add ax,[bx]
            cmp ax,[si]
            je @@case2

            mov ax,[si]
            add ax,[di]
            cmp ax,[bx]
            je @@case3
            jmp @@default

@@case1:    mov ax,[di]
            jmp @@print

@@case2:    mov ax,[si]
            jmp @@print

@@case3:    mov ax,[bx]
            jmp @@print

@@default:  mov di,offset ans3
            call putStr
            jmp @@end

@@print:    mov di,offset ans
            call putStr
            call printDec
            mov di,offset ans2
            call putStr

@@end:      call putNewline
            mov ah,04ch ; fin de programa
            mov al,0
            int 21h
Principal   ENDP
; --- procedimientos ----;
separateArgs PROC
			push ax
            push bx
            push cx
            push dx
			push di
            push si
			mov cx,ARGSSIZE
			mov bx,0
			mov si,0
			mov dx,0
@@while:
			mov al,args[di]
			cmp al,' '
			je @@incDX
            cmp dx,0
            je @@incDI
            cmp al,0
            je @@end
            cmp dx,1
            je @@cpy2arg2
			mov arg2[si],al
			inc si
			jmp @@incDI
@@cpy2arg2: mov arg1[bx],al
            inc bx
            jmp @@incDI
@@incDX:    inc dx
@@incDI:    inc di
            loop @@while
@@end:		pop si
			pop di
            pop dx
            pop cx
            pop bx
			pop ax
			ret
separateArgs ENDP
;***************************************************
changeSegment PROC   ;Los argumentos por linea de comandos se encuentran
                     ;en el segmento extra, para facilitar la manipulacion 
                     ;se mueven al segmento de datos
			mov cx,ARGSSIZE
			mov di,0
@@while:	mov al,es:args[di]   ;Se copia el valor de es:args[di] a al
			mov args[di],al      ;Se copia el valor de al a ds:args[di]
			loop @@while
			ret
changeSegment ENDP
;***************************************************
cleanPar	PROC
			push di
			push bx
			mov ax,@data
			mov es,ax
			mov di,0
			mov bx,dx
			mov al,[bx + di + 1] ; se suma 1 porque el primero es un espacio
	@@loop: mov es:args[di], al
			inc di
			mov al,[bx + di + 1]
			cmp al,0
			loopne @@loop
			pop bx
			pop di
			ret
cleanPar	ENDP
;***************************************************
text2dec    PROC
            push bx
            push cx
            push dx
            push si
		    mov ax,0
		    mov bx,0
            mov cx,10d
            mov dx,0
            mov si,0
@@next:     mov al,byte ptr di[bx] 
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
@@end:      mov ax,si
            pop si
            pop dx
            pop cx
            pop bx
            ret
text2dec    ENDP
;***************************************************
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
            mov ax,' '
            call putchar
            pop dx
            pop cx
            pop bx
            pop ax
            ret
printDec    ENDP
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
getChar     PROC     ;Funcion para leer un cahar y almacenarlo en al
            mov ah,1h   ;Selecciona el servicio 01h
            int 21h     ;Llama la interrupcion 21h
            ret
getChar     ENDP
        END   
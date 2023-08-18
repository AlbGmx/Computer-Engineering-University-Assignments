MODEL small
.STACK 100h
LOCALS
    ARGSSIZE EQU 20
.DATA
         args  db ARGSSIZE dup(0)
         pal db 10,13,'No es un palindromo',10,13,0
         noPal db 10,13,'Si es un palindromo',10,13,0
         revPalWord db ARGSSIZE dup(0)

.CODE ;----- Insert program, subrutine call, etc., here
Principal 	PROC
			mov cl, ds:[80] 	
		    mov dx, 81h		   
	   	    call cleanPar		

		    mov ax,@data ;Inicializar DS al la direccion
		    mov ds,ax ; del segmento de datos (.DATA)

            lea di,args
			call changeSegment
            lea si,revPalWord
@@prepareDI:
            cmp byte ptr [di],0
            je @@invertStr
            inc di
            jmp @@prepareDI
@@invertStr:
            dec di
            cmp di,offset args-1
            je @@endRev
            mov al,[di]
            mov [si],al
            inc si
            jmp @@invertStr
@@endStr:   mov byte ptr [si],0            
@@endRev:   lea si,revPalWord
            lea di,args
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
changeSegment PROC   ;Los argumentos por linea de comandos se encuentran
                     ;en el segmento extra, para facilitar la manipulacion 
                     ;se mueven al segmento de datos
            mov cx,ARGSSIZE
            mov bx,0
@@while:    mov al,es:args[bx]   ;Se copia el valor de es:args[di] a al
            mov args[bx],al      ;Se copia el valor de al a ds:args[di]
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
@@loop:
			mov es:args[di], al
			inc di
			mov al,[bx + di + 1]
			cmp al,0
			loopne @@loop
			pop bx
			pop di
			ret
cleanPar	ENDP
;***************************************************
getArg		PROC
			push ax
			push si
			mov cx,ARGSSIZE
			mov si,1
@@loop:
			mov al,args[si]
			cmp al,' '
			jne @@copy
			jmp @@end
@@copy:
			mov di[bx],al
			inc si
            inc bx
			loop @@loop
@@end:			
			pop di
			pop ax
			ret
getArg		ENDP
;***************************************************
palindrome  PROC
            push ax
            push cx
            push si
            mov si,0
            mov cx,ARGSSIZE
            mov bx,0    ;Empezamos suponiendo que no son palindromos
@@compareStr: 
            mov al,revPalWord[si+1]          
            cmp al,0
            je @@isPal
            cmp args[si],al
            jne @@end
            inc si
            loop @@compareStr
@@isPal:    mov bl,1   
@@end:      pop si
            pop cx
            pop ax
            ret 
palindrome  ENDP
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
@@endCheck:
            ret    
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
MODEL small
.STACK 100h
;----- Insert INCLUDE "filename" directives here
INCLUDE procs.inc
;----- Insert EQU and = equates here
LOCALS
.DATA
 
    new_line db 13,10,0	   	   
	; SEG:DESP  --- litte endian parte menor significativa en dirección menor
    lista_ptr dw  1234h, 5678h 
              dw  9abch, 0def0h
  			  dw  2345h, 6789h
              dw  0abcdh, 0ef01h 
              dw  3456h, 7890h
  			  dw  0abcdh, 0abbbh
              dw  1cbch, 0020h 
              dw  45a7h, 1240h
  			  dw  4abch, 897ah
				 ;    :        -- incluir mas los que se requieran	  
.CODE  ;-----   Insert program, subrutine call, etc., here

Principal  	PROC
			mov ax,@data 	;Inicializar DS al la direccion
			mov ds,ax     	; del segmento de datos (.DATA)
			
            lea bx,lista_ptr
            mov cx, ES:[80h]
            mov ch,0
            call printFARptr_List
;           call getMinorFARptr_List
			mov ah,04ch     		; fin de programa
            mov al,0          
            int 21h            
            ret
            ENDP
		   
; --- procedimientos ----
; ------------------------------------------------------------------
; Procedimiento llamado printWordHex que despliega en formato
; hexadecimal una palabra dada en el registro AX 
printWordHex    PROC
                push  ax
                mov al,ah
                call printByteHex  ;Imprime el byte mas significativo
                pop ax
                call printByteHex   ;Imprime el byte menos significativo
                ret
printWordHex    ENDP  
; ------------------------------------------------------------------
; Procedimiento llamado printFARptr que despliega un apuntador
; (tipo FAR) en formato SEG:DESP
;El apuntador esta dado por DX y AX          		  
printFARptr     PROC
                xcgh dx,ax          
                call printWordHex   ;Se imprime el segmento
                push ax
                mov al,':'  ;Separador xxxx : xxxx
                call putchar
                pop ax
                xcgh dx,ax
                call printWordHex   ;Se imprime el desplazamiento
                ret
printFARptr     ENDP
; ------------------------------------------------------------------
; Procedimiento llamado getFARptr que toma de un lugar de la lista
; un apuntador (tipo FAR) y lo retorna en DX y AX. La lista esta dada
; por BX y el lugar está dado por CX 				  
getFARptr       PROC
                push ax
                push cx
                push si
                mov ax,2
                mul cl
                xcgh ax,cx
                mov si,cx
                mov ax,bx[si]
                mov dx,bx[si+2]
                pop si
                pop cx
                pop ax
                ret
getFARptr       ENDP		
; ------------------------------------------------------------------; Procedimiento llamado printFARptr_List que despliega en 
; formato (SEG:DESP) una lista de apuntadores. La lista está dada por 
; el registro BX y la cantidad de apuntadores en la lista por CX. 
; Este procedimiento hace uso del procedimientos getFARptr y printFARptr 				  
printFARptr_List    PROC
                    push cx
                    push dx 
                    push si
                    mov si,0
                    mov dx,0
                    xcgh dx,cx
@@printList:        call getFARptr
                    call printFARptr
                    push dx
                    lea dx,new_line
                    call puts
                    pop dx
                    inc cx
                    dec dx 
                    jnz @@printList
                    pop si
                    pop dx
                    pop cx
                    ret
printFARptr_List    ENDP			  
; ------------------------------------------------------------------
; Procedimiento llamado cmpFARptr_Minor que compara dos apuntadores
; (tipo FAR) y retorna el menor en DX y AX 	
cmpFARptr_Minor PROC


                ret
cmpFARptr_Minor ENDP	
; ------------------------------------------------------------------
; Procedimiento llamado getMinorFARptr_List retorna en DX y AX el 
; apuntador que apunta a la menor dirección. La lista está dada por el
; registro BX y la cantidad de apuntadores en la lista por CX. 
; Este procedimiento hace uso de los procedimientos getFARptr y cmpFARptr_Minor					   
getMinorFARptr_List PROC
                    push cx
                    push dx 
                    push si
                    mov si,0
                    mov dx,0
                    xcgh dx,cx
@@printList:        call getFARptr
                    inc cx
                    dec dx 
                    jnz @@printList
                    pop si
                    pop dx
                    pop cx
                    ret
getMinorFARptr_List ENDP			   
; ------------------------------------------------------------------		   
printByteHex    PROC
                push ax      ; salvar registros a utilizar
                push bx
                push cx
                mov ah,0     ; asegurar AX = AL
                mov bl,16    ;  
                div bl       ; dividir AX/16  --> cociente en AL y residuo AH
                mov cx,2     ; para imprimir dos digitos hex
@@nxt:          cmp al,10    ; verifica si cociente AL es menor a 10
                jb @@print  
                add al,7   
@@print:        add al,30h   ; si es menos a 10 sumar 30h de lo contrario 37h
                call putchar
                mov al,ah    ; pasa residul (AH) a AL para imprimirlo
                loop @@nxt   ; proximo digito
                pop cx
                pop bx
                pop ax       ; recupera registos utilizados
                ret
printByteHex    ENDP  
  END
MODEL small
.STACK 100h
LOCALS     
.DATA
    string db 10,13,'Cadena apuntada por BX',0
.CODE ;----- Insert program, subrutine call, etc., here
Principal   PROC
            mov ax,@data ;Inicializar DS al la direccion
            mov ds,ax ; del segmento de datos (.DATA)
            mov ax,0
            mov es,ax 	;Las interrupciones se encuentran desde 0 a 3FF;
			CLI			;Desactiva la bandera de interrupciones 
			mov word ptr es:[88h], offset int22		;Se pone la direccion de la interrupcion en el vector 
			mov word ptr es:[8Ah], cs				;Indicamos en donde buscar el codigo (segmento de codigo)
			STI 		;Vuelve a activarlas
			
			mov ah,1	;Selecciona la interrupcion 1
			mov al,'$'	;Pone el char $ en al
			int 22h		;Llama la interrupcion 23 (la creada)

			lea bx,string	;Apunta bx al string
			mov ah,2		;Selecciona la interrupcion 1
			int 22h		   	;Llama la interrupcion 23 	

			mov ah,04ch ; fin de programa
			mov al,0
			int 21h
			ret
Principal   ENDP
; --- procedimientos ----;
;***************************************************
int22       PROC FAR
			push ax
			push dx
			push bx
			  
			cmp ah,1		;Servicio 1
			je @@putchar
			cmp ah,2		;Servicio 2
			je @@puts
			jmp @@end
				
@@putchar:	mov ah,0Eh	;Selecciona el servicio 0Eh
			int 10h		;llama la interrupción para imprimir char
			jmp @@end
				
@@puts:	   	mov ah,0Eh	;Selecciona el servicio 0Eh
@@loop:	   	mov al,[bx]	;Obtiene el char
			cmp al,0	;Si es 0, deja de imprimir
			je @@end
			int 10h		;si no es 0, imprime
			inc bx		;aumenta para siguiente char
			jmp @@loop
				
@@end:	   	pop bx
			pop dx
			pop ax
			iret
int22       ENDP
	END
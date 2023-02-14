MODEL small

LOCALS

.DATA
    aux dw 0

.CODE
public _mulMat3x3
_mulMat3x3  PROC
         push bp
         mov bp,sp
         push ax
         push bx
         push cx
         push dx
         push di
         
@@loop:  push cx
         mov ch,0	
         mov bl,3
         sub bl,cl

@@nxt3:  mov bh,0
         mov aux,0

@@nxtnum:   mov di,[bp+4]
			mov ah,0
			mov al,3
			mov dl,bl		
			mov dh,bh		
			call getnumMat
			push ax
			
			mov di,[bp+6]
			mov ah,0
			mov al,3
			mov dl,bh		
			mov dh,ch	
			call getnumMat
			
			pop dx			
			mul dx
			
			add aux,ax
			
			inc bh
			cmp bh,3
			jne @@nxtnum
			
			push cx
			mov di, [bp+8]
			mov al,3
			mov dl,bl	
			mov dh,ch	
			mov cx,aux
			call setnumMat
			pop cx
			
			inc ch
			cmp ch,3
			jne @@nxt3
			
			pop cx
			loop @@loop
            pop di
            pop dx
            pop cx
            pop bx
            pop ax
			pop bp
			ret
_mulMat3x3  ENDP
;***************************************************
getnumMat	PROC	
			push bx
			push di
			
			mul dl
			add al,dh
			mov bx,ax
			mov al,di[bx]	
			mov ah,0
		
			pop di
			pop bx
			ret
			ENDP
;***************************************************
setnumMat	PROC	
			push ax
			push bx
			push cx
			push di
			
			mul dl
			add al,dh
			mov bx,ax
			mov di[bx],cl	
		
			pop di
			pop cx
			pop bx
			pop ax
			ret
			ENDP
;***************************************************

            mov dl, [si]
            add dl,'0'
            mov ah, 2
            int 21h
            mov dl, [di]
            add dl,'0'
            mov ah, 2
            int 21h
            mov dl, [bx]
            add dl,'0'
            mov ah, 2
            int 21h
            pop bp
            ret
END
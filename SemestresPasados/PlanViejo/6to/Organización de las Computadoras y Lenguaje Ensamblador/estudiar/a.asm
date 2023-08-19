
_outport    PROC
            push bp
            mov bp,sp
            mov dx, [bp + 4]
            mov ax, [bp + 6]
            out dx,ax
            pop bp
            ret
_outport    ENDP


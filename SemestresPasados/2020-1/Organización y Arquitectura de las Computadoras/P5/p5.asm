section .data ; Datos inicializados
    NL: db 13, 10
    NL_L: equ $-NL

section .bss ; Datos no inicializados
    N resb 4
    M resb 4
    cad resb 16

section .text
global _start:

_start:
    ;prueba inicial
    mov eax,0C2966271h
    mov esi, cad
    call printHex
    call printNl

    mov eax, 4
    mov ebx, 1
    mov ecx, NL
    mov edx, NL_L
    
    ;Almacenar matricula en variable M
    mov eax, 1261509h
    mov [M], eax
    call printHex
    call printNl
    
    ;Almacenar 0x4F89193C en EBX
    mov ebx, 4F89193Ch
    mov eax,ebx
    call printHex
    call printNl
    
    ;Almacenar 0x7924B4 en variable N como un dato de 32b
    mov eax, 7924B4h
    mov [N], eax
    call printHex
    call printNl
    
    ;Copiar BX a CX
    mov eax, ecx
    call printHex   ;Mostramos ECX
    mov eax, ebx
    call printHex   ;Mostramos EBX
    mov cx, bx
    mov eax,ecx
    call printHex   ;Mostramos ECX
    call printNl
    
    ;Almacenar LSB de ECX en N
    mov eax, [N]
    call printHex   ;Mostramos N
    
    shr ECX,1
    jc  .one
    mov bl,0h
    jmp .store
.one:
    mov bl,0FFh
.store:
    and al,bl
    mov [N], eax
    
    call printHex
    call printNl
    
    ;Almacenar 0x945 en N como un dato de 16b
    mov ax, 945h
    mov [N], ax
    mov eax, [N]
    call printHex
    call printNl
    
    ;Copiar a ESI la variable N
    mov esi, N
    call printHex
    call printNl

    mov eax, 1
    mov ebx,0
    int 80h
printHex:
    pushad
    mov edx, eax
    mov ebx, 0fh
    mov cl, 28
.nxt: shr eax,cl
.msk: and eax,ebx
    cmp al, 9
    jbe .menor
    add al,7
.menor:add al,'0'
    mov byte [esi],al
    inc esi
    mov eax, edx
    cmp cl, 0
    je .print
    sub cl, 4
    cmp cl, 0
    ja .nxt
    je .msk
.print: mov eax, 4
    mov ebx, 1
    sub esi, 8
    mov ecx, esi
    mov edx, 8
    int 80h 
    call printNl
    popad
    ret
printNl: 
    pushad
    mov eax, 4
    mov ebx, 1
    mov ecx, NL
    mov edx, NL_L
    int 80h
    popad
    ret

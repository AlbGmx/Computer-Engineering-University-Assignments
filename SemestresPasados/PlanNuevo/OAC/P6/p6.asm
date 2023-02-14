section .data ; Datos inicializados    
    NL: db 13, 10
    NL_L: equ $-NL

section .bss ; Datos no inicializados
   ;Reservar dos espacios en memoria no inicializados, uno de 64 bytes etiquetado como A.
   A resb 64
   ;El otro de 1 byte etiquetado como N.
   N resb 1
   ;Cadena temporal utilizada para imprimir
   cad resb 16

section .text
   global _start:

_start:
   ;Solicitar una cadena que se almacene en A.
   mov eax, 3  ;servicio
   mov ebx, 0  ;Entrada
   mov ecx, A  ;Cadena
   mov edx, 64 ;Caracteres
   int 80h 
   call printA
   call printNl

   ;Copiar el primer carácter de A en la variable N. Use un modo de direccionamiento base.
   xor eax,eax     ;Limpiamos EAX
   mov ebx, A  ;Apuntamos las cadenas a manipular
   mov edx, N
   mov al, [ebx] ;obtenemos el primer caracter de A
   mov [edx], al ;Lo guardamos en N
   call printN
   call printNl
   call printNl

   ;Reemplazar el tercer carácter A por un guion -, usando un modo de direccionamiento base con desplazamiento
   mov byte [ebx+2], '-'
   call printA
   call printNl

   ;Reemplazar el octavo carácter de A por una X usando un direccionamiento base con índice escalado.
   mov esi,1
   mov byte [ebx+esi*8], 'x'
   call printA 
   call printNl

   ;Copiar el segundo carácter de A y almacenarlo en los bits 8-15 del acumulador
   xor eax,eax  ;Limpiamos los registros
   xor edx,edx
   mov ecx,8
   mov dl, [ebx+1]   ;Obtenemos el segundo caracter de A 
   add al,dl   ;Lo guardaamos en A
   shl eax,cl   ;Lo recorremos para guardar el valor en los bits de 8 a 15
   call printHex
   call printNl

   ;Reemplazar el noveno carácter de A por el carácter en los bits 8-15 del acumulador, usando un direccionamiento base con índice escalado y desplazamiento.
   mov cl,8
   shr eax,cl 
   mov [ebx+esi*8+1], al
   call printA
   call printNl

   ;terminar proceso
   mov eax, 1
   mov ebx,0
   int 80h

   printA:            ;Imprime A
   pushad
   mov eax, 4
   mov ebx, 1
   mov ecx, A
   mov edx, 64
   int 80h
   popad
   ret  

   printN:            ;Imprime N
   pushad
   mov eax, 4
   mov ebx, 1
   mov ecx, N
   mov edx, 1
   int 80h
   popad
   ret
   
   printNl:            ;Imprime un salto de linea
   pushad
   mov eax, 4
   mov ebx, 1
   mov ecx, NL
   mov edx, NL_L
   int 80h
   popad
   ret
    
   printHex:
   pushad
   mov esi,cad
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
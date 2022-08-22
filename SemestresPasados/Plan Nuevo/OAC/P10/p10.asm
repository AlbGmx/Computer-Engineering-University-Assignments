section .data
   cad: db "1234",0
   char: db 0
   NL: db 13,10
   NL_L: equ $-NL

section .bss 
   temp resb 8
   temp2 resb 8


section .text
global _start:
_start:

   mov edx, cad
   call atoi
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   mov eax,1111
   mov ebx,7
   call modulo
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   mov eax,57
   mov ebx,6
   call modulo
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   mov eax,9142
   mov ebx,6
   call modulo
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   mov eax,45
   mov ebx,25
   call alg
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   mov eax,252
   mov ebx,198
   call alg
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   mov eax,588
   mov ebx,144
   call alg
   call printNl
   mov ebx,10
   mov esi,temp2
   call printNumBase

   ;End program
   mov eax,1
   mov ebx,0
   int 80h

atoi:
   push ebx
   push edx
   push esi
   push edi
   push ecx

   mov eax,0
   mov ebx,10
   mov edi,edx
   mov esi,0
   mov ecx,0

   mov dl,[edi+esi]
   inc esi
   sub dl,'0'
   cmp dl,9 
   ja .endCicle

.cicle:
   add al,dl
   mov dl,[edi+esi]
   inc esi
   sub dl,'0'
   cmp dl,9 
   ja .endCicle
   push edx
   mul ebx   
   pop edx
   jmp .cicle

.endCicle:
   pop ecx
   pop edi
   pop esi
   pop edx
   pop ebx
   ret

printOriginalValue:
   pushad
   mov esi,temp2
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
.print: 
   mov eax, 4
   mov ebx, 1
   sub esi, 8
   mov ecx, esi
   mov edx, 8
   int 80h  
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
   
printNumBase:
   pushad   
   mov edi,0
   mov bh,0 
   mov ecx,0
.cicle:   mov edx,0
   div ebx
   cmp dl,10d
   jb .direct
   add dl,7

.direct add dl,'0'
   mov [temp+edi],dl  

   inc edi
   inc cl
   cmp eax,0
   jnz .cicle 
   mov ebx,esi 
   mov esi,0  
   push ecx

.revNum:
   mov al,[temp+ecx-1]
   mov [ebx+esi],al
   inc esi
   loop .revNum
   
   ;Imprimir cadena
   mov eax, 4  ;Servicio
   mov ecx, ebx
   mov ebx, 1  ;Salida
   pop edx
   int 80h 
   call printNl
   popad
   ret

modulo:
   mov edx,0
.module:
   sub eax,ebx
   cmp eax,ebx
   jb .endModule
   jmp .module
.endModule:
   ret

alg:
.while:
   cmp eax,ebx
   je .endWhile
   jb .BminusA
   sub eax,ebx
   jmp .while
.BminusA:
   sub ebx,eax
   jmp .while
.endWhile:
  ret
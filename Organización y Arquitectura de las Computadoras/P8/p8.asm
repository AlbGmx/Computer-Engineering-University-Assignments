section .data
   NL: db 13, 10
   NL_L: equ $-NL
   ClauseText: db 10,13,"Inciso "
   ClauseText_L: equ $-ClauseText
   ClauseLetter: db "a)",10,13
   ClauseLetter_L: equ $-ClauseLetter
   Cad1: db "Hello World"
   Cad1_L: equ $-Cad1
   char: db 'h-'

section .bss
   Cad resb 8
   temp resb 8
   Cad2 resb 64
   Cad2_L resb 8

section .text
global _start:
_start:
   call printClause
;   mov eax,0AB385h
   mov eax,12345678h
;   mov bl,10
   mov bl,16
 
   mov esi,Cad
   call printOriginalValue
   call printNumBase

   mov eax,6A4B9D01h
   mov bl,16
   mov esi,Cad
   call printOriginalValue
   call printNumBase
   
   mov eax,47845384h
;   mov bl,12
   mov bl,16
   mov esi,Cad
   call printOriginalValue
   call printNumBase
   
   mov eax,2531DEh
   mov bl,16
;   mov bl,2
   mov esi,Cad
   call printOriginalValue
   call printNumBase
  
   call printClause
   mov eax,0EEEEEEFFh
;   call printOriginalValue
;   mov cl,0
;   call clearBit
;   mov cl,1
;   call clearBit
;   mov cl,2
;   call clearBit
;   mov cl,3
;   call clearBit
   mov bl,8
   mov esi,Cad
   call printNumBase

  
   call printClause
  
   call printClause
  
   call printClause
  
   call printClause
  
   call printClause
  
   call printClause
   

   ;End program
   mov eax,1
   mov ebx,0
   int 80h

Func1:
  pushad
  mov ecx,Cad1_L
  mov [Cad2_L],ecx
  add esi,ecx
.rev:
  mov al,[esi-1]
  mov [edi+esi],al
  inc edi
  dec esi
  loop .rev
  sub edi,ecx

  mov eax, 4  ;Servicio
  mov ebx, 1  ;Salida
  mov ecx, Cad2
  mov edx, [Cad2_L]
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
   pushad
   mov [char],dl
   mov eax,4
   mov ebx,1
   mov ecx,char
   mov edx,2
   int 80h  
   popad
   mov [temp+edi],dl
   inc edi
   inc cl
   cmp eax,0
   jnz .cicle 
   mov ebx,esi 
   mov esi,0  
   push ecx
   dec ecx

.revNum:
   mov eax,[temp+ecx]
   mov [ebx+0],eax
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

setBit:
   ror eax,cl
   or eax,1
   rol eax,cl
   ret

clearBit:
   ror eax,cl
   and eax,0FFFFFFFEh
   rol eax,cl
   ret   
   
notBit:
   ror eax,cl
   xor eax,1
   rol eax,cl
   ret

testBit:
   push eax
   ror eax,cl
   xor eax,0FFFFFFFEh
   rcr eax,1
   pop eax
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

printClause:
   pushad
   ;Imprimir "Inciso "
   mov eax, 4  ;Servicio
   mov ebx, 1  ;Salida
   mov ecx, ClauseText
   mov edx, ClauseText_L
   int 80h 
   ;Imprimir "x)"
   mov eax, 4  ;Servicio
   mov ebx, 1  ;Salida
   mov ecx, ClauseLetter
   mov edx, ClauseLetter_L
   int 80h 
   add byte [ClauseLetter],1
   popad
   ret
printOriginalValue:
   pushad
   mov esi,Cad
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
   mov byte[char],'h'
   mov eax,4
   mov ebx,1
   mov ecx,char
   mov edx,2
   int 80h   

   popad
   ret
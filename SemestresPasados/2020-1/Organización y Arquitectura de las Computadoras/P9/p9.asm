section .data
   NL: db 13, 10
   NL_L: equ $-NL
   ClauseText: db 10,13,"Inciso "
   ClauseText_L: equ $-ClauseText
   ClauseLetter: db "a)",10,13
   ClauseLetter_L: equ $-ClauseLetter
   Zero: db "El bit es cero",10,13
   Zero_L: equ $-Zero
   One: db "El bit es uno",10,13
   One_L: equ $-One
   Cad1: db "Hello World"
   Cad1_L: equ $-Cad1
   char: db 'h-'

section .bss
   Cad resb 8
   temp resb 8
   Cad2 resb 8
   Cad2_L resb 8
   Cad3 resb 64
   Cad3_L resb 8

section .text
global _start:
_start:
   call printClause
   mov eax,0AB385h
   mov bl,10
   mov esi,Cad
   call printOriginalValue
   call printNumBase
   call printNl

   mov eax,6A4B9D01h
   mov bl,16
   mov esi,Cad
   call printOriginalValue
   call printNumBase
   call printNl   

   mov eax,47845384h
   mov bl,12
   mov esi,Cad
   call printOriginalValue
   call printNumBase
   call printNl
   
   mov eax,2531D3h
   mov bl,2
   mov esi,Cad
   call printOriginalValue
   call printNumBase
   call printNl
  
   mov byte[char],10
   mov byte[char+1],13
   mov eax,0Fh
   call printClause
   call printOriginalValue
   call printNl
   mov cl,5
   call setBit
   call printOriginalValue
   call printNl

   call printClause
   mov cl,3
   call clearBit
   call printOriginalValue
   call printNl
      
   call printClause
   mov cl,1
   call notBit
   call printOriginalValue   
   call printNl
   
   call printClause
   mov cl,2
   call testBit
   jc .carryOne
   mov eax, 4  ;Servicio
   mov ebx, 1  ;Salida
   mov ecx, Zero
   mov edx, Zero_L
   int 80h
   jmp .next
.carryOne:   mov eax, 4  ;Servicio
   mov ebx, 1  ;Salida
   mov ecx, One
   mov edx, One_L
   int 80h
   
.next:     
   call printClause
   mov esi, Cad1
   mov edi, Cad2
   call Func1
   call printNl

   call printClause
   mov eax,6
   mov esi,Cad3
   call Func2

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
  mov [edi],al
  inc edi
  dec esi
  loop .rev
  sub edi,ecx

  mov eax, 4  ;Servicio
  mov ebx, 1  ;Salida
  mov ecx, Cad2
  mov edx, Cad1_L
  int 80h
  popad
  ret

Func2:
   cmp eax,10
   jae .exception
   mov ecx,eax
   mov eax,1
   mov esi,0
   mov ebx,ecx
   add bl,'0'
   mov [Cad3+esi],bl
   inc esi

.factorial:
   mul cx
   dec cl
   jz .endFact
   mov bl,'*'
   mov [Cad3+esi],bl
   inc esi
   mov ebx,ecx
   add bl,'0'
   mov [Cad3+esi],bl
   inc esi
   jmp .factorial
.endFact:   
   mov bl,'='
   mov [Cad3+esi],bl
   inc esi 
   mov [Cad3_L],esi
   pushad 
   mov eax, 4  ;Servicio
   mov ebx, 1  ;Salida
   mov ecx, Cad3
   mov edx, esi
   int 80h
   popad
   mov bl,10
   mov esi,Cad
   
   call printNumBase
.exception ret 

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
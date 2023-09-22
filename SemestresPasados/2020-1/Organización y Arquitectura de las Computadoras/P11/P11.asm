section .data

   source: db "123456789",10,13,0
   error: db "xxxxxxxx"
   error_L: equ $-error
   destiny: db "9876543210 string",10,13,0
section .bss 
section .text
global _start:
_start:

   mov esi,source
   mov edi,destiny
   mov ebx,0
   mov ecx,15
   
   call substr

   cmp eax,-1
   je .end
   pushad
   mov eax, 4   ;servicio
   mov ebx, 1   ;Entrada
   mov ecx, edi ;Cadena
   mov edx, 20  ;Caracteres
   int 80h 
   popad
 
.end:  

   ;End program
   mov eax,1
   mov ebx,0
   int 80h

substr:
   pushad
   call testStr ;Verificamos los tamaños de ambas cadenas

   cmp eax,-1
   je .sizeError
   xchg esi,ebx
      
.cicle:
   mov al,[ebx+esi]
   mov [edi],al
   inc edi
   inc esi
   loop .cicle
   popad
   mov eax,0
   jmp .end

.sizeError:
   popad   
   mov eax,-1
.end:
   ret

;Obtenemos el tamaño de la cadena
testStr:
   pushad
   push ecx
   push edi
   mov edi,esi
  
   call getLenght ;obtiene el tamaño de la cadena en edi
  
   cmp eax,ecx
   jle .sizeError
   add ecx,ebx
   cmp eax,ecx
   jl .sizeError
   
   pop edi
   pop ecx
   call getLenght

   cmp eax,ecx
   jle .sizeError
   cmp eax,ecx
   jae .endTest

.sizeError:
   popad
   mov eax,-1   
   jmp .endError

.endTest:
   popad
   mov eax,0
.endError:
   ret

;Obtiene el tamaño de una cadena (Asusmiendo que termina en 0x0)
getLenght:
   push ecx
   push ebx
   push edi
   mov ebx,edi
   mov eax,0 ;caracter a buscar
   mov ecx,100 
   cld
   repne scasb ;repne = repetir mientras no sea igual
   ;scasb = buscar un caracter (byte *al*) en una cadena (ebx)
   
   sub edi,ebx ;Obtenemos la diferencia
   mov eax,edi
   
   pop edi
   pop ebx
   pop ecx
   ret








f
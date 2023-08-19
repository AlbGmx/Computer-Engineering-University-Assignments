section .data
   buffer: db "1"
   newLine: db 10,13
   newLine_L: equ $-newLine
   fileName: db "OAC_P12.txt",0
section .bss 
   str_piramid: resb 64
   fdOut resb 1
   fdIn resb 1
   fileBuffer resb 26
section .text

global _start:

_start:
   mov ebx,str_piramid
   mov ecx,35
   call piramid

  ;Imprimir cadena
   mov eax, 4  ;servicio
   mov ebx, 1  ;Entrada
   mov ecx, str_piramid+4;Cadena
   mov edx, [str_piramid]  ;Caracteres
   int 80h 

;  Crear archivo
   mov eax,8
   mov ebx,fileName
   mov ecx,0777
   int 80h
   mov [fdOut],eax

;  Escribir a archivo
   mov eax,4
   mov ebx,[fdOut]
   mov ecx,str_piramid+4
   mov edx,[str_piramid]
   int 80h

;  Cerrar archivo
   mov eax,6
   mov ebx, [fdOut]   
   int 80h

;  Abrir archivo
   mov eax,5
   mov ebx,fileName
   mov ecx,0
   mov edx, 0777
   int 80h
   mov [fdIn],eax

;   Leer de archivo
   mov eax,3
   mov ebx, [fdIn]
   mov ecx, fileBuffer
   mov edx, [str_piramid]
   int 80h

;  cerrar archivo
   mov eax,6
   mov ebx, [fdIn]
   int 80h

;  imprimir fileBuffer
   mov eax, 4
   mov ebx, 1
   mov ecx, fileBuffer
   mov edx, [str_piramid]
   int 0x80

.end:  
   ;End program
   mov eax,1
   mov ebx,0
   int 80h


;Funcion piramid, obtiene en ecx el tamaño de la piramide
;   obtiene en ebx el espacio reservado en memoria para guardar la piramide
;   guarda el numero de caracteres en los primeros 32b de memoria reservada
;   para obtener el numero de caracteres se utiliza la instruccion mov ecx,[ebx]
piramid:
   add ebx,4
   mov esi,ebx
   mov al,'9'
   mov edx,101h
.cicle:   
.while:
   pushad 
   mov al,[buffer]
   mov [ebx],al
  ;Imprimir cadena
   mov eax, 4  ;servicio
   mov ebx, 1  ;Entrada
   mov ecx, buffer;Cadena
   mov edx, 1  ;Caracteres
   int 80h 
   popad
   inc ebx
   dec dl
   cmp dl,0
   jne .while
   call newLn
   inc dh
   push eax
   mov al,10
   mov [ebx],al
   mov al,13
   inc ebx
   mov [ebx],al
   pop eax
  inc ebx
   mov dl,dh
   cmp al,[buffer]
   je .num2letters
   inc byte[buffer]
   
   loop .cicle
   jmp .end
.num2letters:
   add byte[buffer],8
   loop .cicle
.end:
   sub ebx,esi
   mov [str_piramid],ebx
   ret
newLn:
   pushad 
  ;Imprimir cadena
   mov eax, 4  ;servicio
   mov ebx, 1  ;Entrada
   mov ecx, newLine;Cadena
   mov edx, newLine_L  ;Caracteres
   int 80h 
   popad
   ret

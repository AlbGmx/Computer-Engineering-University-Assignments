%include "pc_io.inc"

section .data    ; Datos inicializados
   msg1:     db "Ingresa tu nombre: ",10,0
   msg2:     db "Hola ",0
   msg3:     db 10,"Ingresa un caracter: ",0 
   msg4:     db 10,"Ingresaste: ",0 
   
section .bss     ; Datos no inicializados
   nombre    resb 256   
   car       resb 1   
   
section .text
   global _start:
   
_start:   

   call clrscr     ; limpiar pantalla
   mov edx, msg1   ; desplegar mensaje
  call puts
   
   mov eax, 3
   mov ebx, 0
   mov ecx, nombre
   mov edx, 256
   int 80h 

   mov edx, msg2
   call puts    
   mov edx, nombre
   call puts

   mov edx, msg3
   call puts
   call getche    ; ingresar un caracter que se almacena en AL, el caracter se muestra en pantalla
   
   mov edx, msg4
   call puts
   call putchar  ; desplegar caracter en AL

   mov al,10
   call putchar  ; desplegar salto de linea
   
   mov eax, 1
   mov ebx,0
   int 80h

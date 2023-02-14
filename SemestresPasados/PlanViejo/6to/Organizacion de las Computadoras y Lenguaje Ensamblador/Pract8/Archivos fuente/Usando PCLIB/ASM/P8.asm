MODEL small
   .STACK 100h
 
 INCLUDE procs.inc
       LOCALS
   .DATA
      animal db 5,?,5 dup(0)
      ask db 'Ingrese un nombre de un animal', 10,13,'(Animales soportados: gato, mono, leon, rana y pavo): ',0
      answer db 'Animal ingresado: ',0
      xceptn  db 'Animal ingresado no soportado...',0
      cat db 'El gato hace miau...',0
      monkey db 'El mono hace uh uh ah ah...',0
      lion db 'El leon hace roar...',0
      frog db 'La rana hace croac croac...',0
      turkey db 'El pavo hace glu glu...',0
      gato db 'gato',0
      mono db 'mono',0
      leon db 'leon',0
      rana db 'rana',0
      pavo db 'pavo',0
      
   .CODE
    ;-----   Insert program, subrutine call, etc., here

Principal  	PROC
         mov ax,@data 	;Inicializar DS al la direccion
         mov ds,ax     	; del segmento de datos (.DATA)     
         mov dx,offset ask    ;Pide que se ingrese un animal
         call puts            
         mov dx,offset animal ;Pone la etiqueta en la que se guardara lo que se lea 
         call gets          ;Lee del teclado

         call putNewline
         mov dx,offset answer ;Muestra el mensaje de que se ha capturado algo
         call puts

         mov dx,offset animal+2  ;Muestra el animal capturado
         call puts
         mov di,offset animal+2  ;Muestra el animal capturado
         call compareString   ;Compara el string capturado di, con los animales soportados, el resultado se guarda en bl            
         cmp bl,2h            ;Si el resultado es 2h, no se encontro ningun animal soportado
         je @@exception

         ;bl indica el animal encontrado y se imprime su mensaje
         cmp bl,3h   
         je @@gato   

         cmp bl,4h
         je @@mono

         cmp bl,5h
         je @@leon

         cmp bl,6h
         je @@rana            

         cmp bl,7h
         je @@pavo
         ;si no se encuentra un animal, imprime una excepcion (Esta linea no deberia suceder)
         ;pero se pone solo por si se llega a dar el caso
         jmp @@exception 

@@gato:  mov dx,offset cat   
         jmp @@print
@@mono:  mov dx,offset monkey
         jmp @@print
@@leon:  mov dx,offset lion
         jmp @@print
@@rana:  mov dx,offset frog
         jmp @@print
@@pavo:  mov dx,offset turkey
         jmp @@print
@@exception:
         mov dx,offset xceptn
@@print: call putNewline   ;Imprime el salto de linea y el mensaje en di
         call puts
@@endProgram:
            call putNewline
				mov ah,04ch	     ; fin de programa
				mov al,0             ;
				int 21h              ; 
         ENDP

gets   PROC
      mov ah, 0Ah          ;Se selecciona el servicio 0Ah 
	int 21h              ;Se llama a la interrupcion 21h
      mov bl,animal[1]     ;Despues de utilizar la interrupcion 21h es necesario 
      mov animal[bx+2], 0  ;agregar el caracter de terminacion manualmente
         ENDP              ;El tamaño del string se encuentra en la segunda posicion

compareString PROC
      push di              ;Guarda el valor del reg di
      call toLower         ;Convierte todas las mayusculas encontradas a minusculas
      cmp bl,2h            ;Si se encuentra una exception (al menos un char no esta dentro del alfabeto)
      je @@endCmp          ;  Temina la comparacion
      call compareAnimal   ;En cualquier otro caso, se compara el str uno a uno con los animales
@@endCmp:   
      pop di               ;Se recupera el registro usado
      ret 
         ENDP

compareAnimal    PROC
      push ax           ;Se guardan los registros a utilizar
      push cx
      push di
      push dx
      mov cx,0h         ;Se resetea CX
      mov al,[di]       ;Se obtiene el primer char de la cadena en DI
      cmp al,'g'        ;Si es 'g'
      je @@gato         ;Se continua la comparacion con gato
      cmp al,'m'        ;Si es 'm'  
      je @@mono         ;Se continua la comparacion con mono
      cmp al,'l'        ;Si es 'l'       
      je @@leon         ;Se continua la comparacion con leon
      cmp al,'r'        ;Si es 'r'  
      je @@rana         ;Se continua la comparacion con rana
      cmp al,'p'        ;Si es 'p'  
      je @@pavo         ;Se continua la comparacion con pavo
      jmp @@exception   ;En cualquier otro caso, manda una excepcion
@@gato: 
      inc di            ;Incrementa di y cx
      inc cx            
      mov al,[di]       ;Se obtiene el valor de di
      cmp al,0h         ;Si es un caracter de terminacion
      je @@gatoCheck    ;Revisa el resultado      
      mov bx,cx         ;Se copia el valor de cx en bx   
      cmp al,gato[bx]   ;Se otiene el char de gato, desplazado por bx (si bx=1, se obtiene una 'a')        
      je @@gato         ;Si son iguales, sigue comparando   
      jmp @@exception   ;En cualquier otro caso, manda una excepcion         
@@gatoCheck:
      cmp cx,04h        ;Debido a que los animales son de 4 letras, cx debe terminar en 4
      jne @@exception
      mov bl, 03h ;03h indica que el gato ha sido encontrado
      jmp @@endCompare
@@mono:  
      inc di
      inc cx
      mov al,[di]
      cmp al,0h
      je @@monoCheck
      mov bx,cx
      cmp al,mono[bx]
      je @@mono
      jne @@exception
@@monoCheck:
      cmp cx,04h
      jne @@exception
      mov bl, 04h ;04h indica que el mono ha sido encontrado
      jmp @@endCompare
@@leon:
      inc di
      inc cx
      mov al,[di]
      cmp al,0h
      je @@leonCheck
      mov bx,cx
      cmp al,leon[bx]
      je @@leon
      jne @@exception
@@leonCheck:
      cmp cx,04h
      jne @@exception
      mov bl, 05h ;05h indica que el leon ha sido encontrado
      jmp @@endCompare
@@rana:
      inc di
      inc cx
      mov al,[di]
      cmp al,0h
      je @@ranaCheck
      mov bx,cx
      cmp al,rana[bx]
      je @@rana
      jne @@exception
@@ranaCheck:
      cmp cx,04h
      jne @@exception
      mov bl, 06h ;06h indica que la rana ha sido encontrada
      jmp @@endCompare
@@pavo:
      inc di
      inc cx
      mov al,[di]
      cmp al,0h
      je @@pavoCheck
      mov bx,cx
      cmp al,pavo[bx]
      je @@pavo
      jne @@exception
@@pavoCheck:
      cmp cx,04h
      jne @@exception
      mov bl, 07h ;07h indica que el pavo ha sido encontrado
      jmp @@endCompare
@@exception:
      mov bl,02h
      jmp @@endCompare
@@endCompare: 
      pop dx
      pop di
      pop cx
      pop ax
      ret
         ENDP

               ;Comprueba que al se encuentre dentro del alfabeto    
isAplha  PROC  ;Si no esta dentro devuelve 02h en bl, si es mayuscula 01h, si es minuscula 00h
      push ax
      ;Para que este en el alfabeto mayuscula debe cumplirse ('A' >= x <= 'Z')
      cmp al,'A' 
      jl @@exception 
      cmp al,'Z' 
      jl @@isUpper
      ;Para que este en el alfabeto minuscula debe cumplirse ('a' >= x <= 'z')
      cmp al,'a' 
      jl @@exception
      cmp al,'z' 
      jl @@isLower  
      ;Si no se cumple ningun caso anterior, no esta en el alfabeto
      jmp @@exception 
@@exception:
      mov bl,2h
      jmp @@endCheck
@@isUpper:
      mov bl,1h
      jmp @@endCheck
@@isLower:
      mov bl,0h
@@endCheck:
      pop ax   ;Recupera registro
      ret    
         ENDP

toLower PROC      ;Convierte todas las mayusculas encontradas a minusculas
      push ax
      push di
@@convStr:         
      mov al,[di]
      cmp al,0h         ;Si el caracter es el de terminacion
      je @@endConvStr   ;Termina conversion
      call isAplha      ;Se revisa si esta en el abecedario y si es mayuscula o minuscula
      cmp bl,2h         ;Si no se encuentra en el abecedario
      je @@endConvStr   ;Se deja de convertir
      cmp bl,01h        ;Si es mayuscula
      je @@upper2Lower  ;Convierte a minuscula
      inc di            ;Incrementa di
      jmp @@convStr     ;Sigue convirtiendo
@@upper2Lower:
      add al,' '        ;Se le suma ' ' que equivale a la diferencia entre 'A' y 'a' (20h)
      mov [di],al       ;Se guarda el char, ahora en minuscula
      inc di            ;Incrementa di
      jmp @@convStr     ;Sigue convirtiendo
@@endConvStr:
      pop di            ;Recupera registros utilizados
      pop ax
      ret
         ENDP

putNewline PROC   ;Funcion  para imprimir un salto de linea
            push ax
            mov al, 0Ah    ;Salto de linea
            call putchar
            mov al, 0Dh    ;Retorno de carro
            call putchar
            pop ax
            ret
         ENDP
         END
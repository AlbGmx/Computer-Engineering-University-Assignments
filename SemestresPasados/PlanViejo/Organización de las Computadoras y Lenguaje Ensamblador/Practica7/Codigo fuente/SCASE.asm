MODEL small
   .STACK 100h
 INCLUDE procs.inc
       LOCALS
   .DATA
      ask   db  'Presione cualquier digito: ',0
      defaultMessage   db  'No ha presionado ningun digito',0
      scaseMessage   db  'El digito presionado fue: ',0

   .CODE
    ;-----   Insert program, subrutine call, etc., here
    Principal  	PROC
				mov ax,@data 	;Inicializar DS al la direccion
				mov ds,ax     	; del segmento de datos (.DATA)

				call clrscr

				mov  dx,offset ask   
				call puts
				
            call getchar   ;Espera una tecla del usuario
            call println   ;Imprime un salto de linea

            mov bl,30h     ;Compara si es char '0'
            cmp al,bl      ;Compara el valor introducido con bl
            JE @@SCASE     ;JMP al case indicado
            
            mov bl,31h     ;Compara si es char '1'     
            cmp al,bl     
            JE @@SCASE     
            
            mov bl,32h     ;Compara si es char '2'      
            cmp al,bl      
            JE @@SCASE     
            
            mov bl,33h     ;Compara si es char '3'
            cmp al,bl      
            JE @@SCASE    
  
            mov bl,34h     ;Compara si es char '4'
            cmp al,bl     
            JE @@SCASE    
  
            mov bl,35h     ;Compara si es char '5'
            cmp al,bl     
            JE @@SCASE    
  
            mov bl,36h     ;Compara si es char '6'
            cmp al,bl     
            JE @@SCASE    
  
            mov bl,37h     ;Compara si es char '7'
            cmp al,bl     
            JE @@SCASE    
  
            mov bl,38h     ;Compara si es char '8'
            cmp al,bl     
            JE @@SCASE    
  
            mov bl,39h     ;Compara si es char '9'
            cmp al,bl     
            JE @@SCASE    
            JMP @@DEFAULT
@@SCASE:  
            mov dx,offset scaseMessage
            call puts  
            mov al,bl      ;Se copia el valor de bl a al
            call putchar   ;imprime el valor almacenado en al
            call println   ;Imprime un salto de linea
            JMP @@EndSwitchCase
@@DEFAULT:
            mov dx,offset defaultMessage
            call puts  
            call println   
            JMP @@EndSwitchCase
@@EndSwitchCase:
				mov ah,04ch	   ; fin de programa
				mov al,0       ;
				int 21h        ; 
                ENDP

println PROC ; Funcion para indicar un salto de linea
                           ;Debido que la función modifica el registro A se hace
            push ax        ;push para guardar su valor en la pila
            mov al,10      ;Salto de línea y
            call putchar
            mov al,13      ;Retorno de carro
            call putchar
            pop ax     ;pop para obtener el valor del registro antes de modificar
            ret
         ENDP; < -- Indica a TASM el fin del procedimiento
         END

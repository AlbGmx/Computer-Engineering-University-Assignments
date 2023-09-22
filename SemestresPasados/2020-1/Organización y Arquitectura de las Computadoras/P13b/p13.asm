global _setBitPort
global _clearBitPort
global _notBitPort
global _testBitPort
_setBitPort:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,1
   rol al,cl
   or al,[ebp+8]
   pop ebp
ret
_clearBitPort:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,0FFFFFFFEh
   rol al,cl
   and al,[ebp+8]
   pop ebp
ret
_notBitPort:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,1
   rol al,cl
   xor al,[ebp+8]
   pop ebp
ret
_testBitPort:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,1
   rol al,cl
   test al,[ebp+8]
   jz .cero
   mov eax,1
   jmp .end
.cero:
   mov eax,0
.end:
   pop ebp
ret

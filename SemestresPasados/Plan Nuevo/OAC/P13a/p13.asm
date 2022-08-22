global _setBit
global _clearBit
global _notBit
global _testBit
_setBit:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,1
   rol al,cl
   or al,[ebp+8]
   pop ebp
ret
_clearBit:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,0FFFFFFFEh
   rol al,cl
   and al,[ebp+8]
   pop ebp
ret
_notBit:
   push ebp
   mov ebp, esp
   mov cl,[ebp+12]
   mov eax,1
   rol al,cl
   xor al,[ebp+8]
   pop ebp
ret
_testBit:
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

inicio-programa
   entero num1
   entero num2
   entero num3
   leer "Ingresar primer número:", num1
   leer "Ingresar segundo número:", num2
   leer "Ingresar tercer número:", num3
   si (num1 > num2)
      entonces
         si (num1 > num3)
            entonces
               escribir "El mayor número es:", num1
            fin-entonces
            sino
               escribir "El mayor número es:", num3
            fin-sino
         fin-si
      fin-entonces
      sino
         si (num2 > num3)
            entonces
               escribir "El mayor número es:", num2
            fin-entonces
            sino
               escribir "El mayor número es:", num3
            fin-sino
         fin-si
      fin-sino
   fin-si
fin-programa
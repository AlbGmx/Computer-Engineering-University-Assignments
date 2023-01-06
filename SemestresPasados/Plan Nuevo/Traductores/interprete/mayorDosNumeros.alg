inicio-programa
   entero num1
   entero num2
   leer "Ingresar primer número:", num1
   leer "Ingresar segundo número:", num2
   si (num1 > num2)
      entonces
         escribir "El mayor número es:", num1
      fin-entonces
      sino
         si (num1 < num2)
            entonces
               escribir "El mayor número es:", num2
            fin-entonces
            sino
               escribir "Los números son iguales"
            fin-sino
         fin-si
      fin-sino
   fin-si
fin-programa

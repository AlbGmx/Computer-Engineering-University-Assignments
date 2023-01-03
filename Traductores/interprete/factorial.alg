inicio-programa
  entero numero 
  entero resultado
  leer "Ingresar un número:", numero
  resultado = 1
  mientras (numero > 0)
    resultado = resultado * numero
    numero = numero - 1
  fin-mientras
  escribir "El factorial es:", resultado
fin-programa

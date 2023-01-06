inicio-programa
   leer "Cuantas calificaciones", n
   x = 0

   repite (i=1, n)
      leer "Da una calificacion", j
      x = x + j
   fin-repite

   x = x / n

   si (x > 5) entonces
      escribir "Aprobado con: ", x
   fin-si

   si (x == 10) entonces
      escribir "Excelente"
   fin-si
fin-programa
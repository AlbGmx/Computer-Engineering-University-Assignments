inicio-programa
    entero numeros
    entero n1 = 0
    entero n2 = 1
    entero count = 0
    entero temp
    leer "Ingresa numero tope: ", numeros

    si (numeros <= 0) 
       entonces
            escribir "Ingresar un numero positivo"  
        fin-entonces
    fin-si

    si (numeros == 1)
        entonces
            escribir "Secuencia Fibonacci hasta: ", numeros
            escribir "",n1
        fin-entonces
    fin-si
    
    si (numeros > 1)
        entonces
            escribir "Secuencia Fibonnaci hasta: ", numeros
            mientras (count < numeros) 
                escribir "",n1
                temp = n1 + n2
                n1 = n2
                n2 = temp
                count = count + 1
            fin-mientras
        fin-entonces
    fin-si
fin-programa
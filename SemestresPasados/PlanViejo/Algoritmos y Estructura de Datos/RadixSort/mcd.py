#Algoritmo de Euclides de dos numeros
def mcd(a, b):
    r = a % b if b != 0 else a
    return b if r == 0 else mcd(b, r)
 
 
def funcion(numbers):
    if len(numbers) >= 2:
        r = mcd(numbers[0], numbers[1])
        for n in numbers[2:]:
            r = mcd(r, n)
        return r
 
 
#codigo inicial
numbers = []
i = 1
try:
    j = int(input("Ingresa el numero de valores a introducir: "))   #Se captura el numero de valores a procesar
except ValueError as e:
        print("\tEl valor ingresado no es un entero valido, se calculara el mcd de dos numeros\n")
        j = 2
while(i <= j):
    try:
        num = int(input("\nIngresa el número {}: ".format(i)))    #Se capturan los valores
        numbers.append(num)
        i += 1
    except ValueError as e:
        print("\tEl valor ingresado no es un entero valido")

result = funcion(numbers)
print("\nEl maximo comun divisor de", numbers, "es:", result)
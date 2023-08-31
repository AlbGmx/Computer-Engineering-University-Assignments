import filtro

def square(n):
    return n*n

numbers = (1,2,3,4)
result = map(square, numbers)

print("Lista de numeros")
print(numbers)
print("funcion map aplicada")
print(list(result))

result = filter(filtro.vocales, "python")

print("python")
print("funcion filtro aplicada")
print(list(result))





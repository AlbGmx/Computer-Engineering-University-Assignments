x = 6
print(type(x))
x = 6.0
print(type(x))
x = "6"
print(type(x))
x = float(6)
print(type(x))

def funcion(a,b):
    return a+b

x = funcion
print(type(x))
x(3,5)

x("Hola", "Mundo")

def imprimirFloat():
    print("Esto es un Flotante")
    
def imprimirEntero():
    print("Esto es un Entero")
    
dispatch = {
    int: imprimirEntero,
    float: imprimirFloat,
    list: lambda: "Esto es una lista"
}

x = 5 
dispatch(type(x))()
x = 5.0 
dispatch(type(x))()
x = list()
dispatch(type(x))()
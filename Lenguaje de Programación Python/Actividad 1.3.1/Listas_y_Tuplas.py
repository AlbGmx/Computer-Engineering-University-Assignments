
lista = []

x = int(input("\n\nIngrese el numero de elementos por capturar: "))
print("El formato de direccion es Calle, numero y codigo postal")
for i in range(x):
      dom = []
      print("\nElemento ", i+1)
      name = input("Nombre: ")
      dom.append(input("Ingrese la calle: "))
      dom.append(input("Ingrese el numero: "))
      dom.append(input("Ingrese el codigo postal: "))
      coor = []
      coor.append(input("Ingrese la latitud: "))
      coor.append(input("Ingrese la longitud: "))
      lista.append([dom, coor])
print(lista)
def createList(lista):
      for i in range(int(input("Ingrese el numero de elementos de la lista: "))):
            print("Ingrese el valor de la posicion", i+1)
            lista.append([input("Nombre: "), input("Clase: "), input("Raza: ")])
            print("\n")
      return lista

lista = []
print(createList(lista))
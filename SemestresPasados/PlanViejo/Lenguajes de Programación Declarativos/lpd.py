# Esta funcion toma al ultimo elemento como piote
# acomoda los elementos mas pequeños a la izquierda
# y los mas grandes a la derecha del pivote 

def partition(array, low, high):
    i = (low-1)         # Indice del primer elemento
    pivot = array[high]     # Pivote
 
    for j in range(low, high):
 
        # Si el elemento actual es mas pequeño o
        # igual al pivote
        if array[j] <= pivot:
 
            # incrementa indice del primer elemento
            i = i+1
            array[i], array[j] = array[j], array[i]
 
    array[i+1], array[high] = array[high], array[i+1]
    return (i+1)
 
# Funcion que implementa la funcion Quicksort
# array[] --> array a ordenar
# low  --> Indice inicial
# high  --> Indice final
  
def quickSort(array, low, high):
    if len(array) == 1:
        return array
    if low < high:
 
        
        pi = partition(array, low, high)
 
        # los elementos se ordenan separademente
        # antes y despues de la particion
        quickSort(array, low, pi-1)
        quickSort(array, pi+1, high)
 
array = [10, 7, 8, 9, 1, 5]
n = len(array)
quickSort(array, 0, n-1)
print("Array ordenado:")
for i in range(n):
    print("%d" % array[i]),

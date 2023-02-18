from math import sqrt
print("\n~~~~~~~~~~~~~~~Tronco de Piramide~~~~~~~~~~~~~~~~")
h = int(input("Altura: "))
a = int(input("Apotema: "))
Ab = int(input("Area Base Mayor: "))
P = int(input("Perimetro Base Mayor: "))
ab = int(input("Area Base Menor: "))
p = int(input("Perimetro Base Menor: "))
A = int(input("Altura de inclinacion: "))

A = ((P+p)/2)*a+Ab+ab
V = ((Ab+ab+sqrt(Ab*ab))*h)/3
print("Formula Area:  ((P+p)/2)*a+Ab+ab,\t Formula Volumen: ((Ab+ab+sqrt(Ab*ab))*h)/3")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
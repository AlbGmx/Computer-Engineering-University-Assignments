print("\n~~~~~~~~~~~~~~~~~~~~Piramide~~~~~~~~~~~~~~~~~~~~")
h = int(input("Altura: "))
A = int(input("Altura de inclinacion: "))
a = int(input("Apotema: "))
Ab = int(input("Area Base: "))
P = int(input("Perimetro Base: "))

A = (P*(a+A))/2
V = (Ab * h) / 3
print("Formula Area:  (P*(a+A))/2,\t Formula Volumen: (Ab * h) / 3")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
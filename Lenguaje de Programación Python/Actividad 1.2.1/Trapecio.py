print("\n~~~~~~~~~~~~~~~~~~~~Trapecio~~~~~~~~~~~~~~~~~~~~")
B = int(input("Base mayor: "))
b = int(input("Base menor: "))
a = int(input("Lado izquierdo: "))
c = int(input("Lado derecho: "))
h = int(input("Altura: "))

A = (h*(B+b)) / 2
P = B + b + a + c
print("Formula Area:  (h*(B+b)) / 2,\t Formula Perimetro: B + b + a + c")
print("A = ", A, "\tP = ", P)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
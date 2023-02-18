from math import pi
print("\n~~~~~~~~~~~~~~~~~~~~~~Cono~~~~~~~~~~~~~~~~~~~~~~")
h = int(input("Altura: "))
g = int(input("Generatriz: "))
R = int(input("Radio Base: "))

A = pi * R * (R + g)
V = (pi * R**2 * h) / 3
print("Formula Area:  pi * R * (R + g),\t Formula Volumen: (pi * R^2 * h) / 3")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
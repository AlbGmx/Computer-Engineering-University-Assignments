from math import pi
print("\n~~~~~~~~~~~~~~~~~~~~Cilindro~~~~~~~~~~~~~~~~~~~~")
h = int(input("Altura: "))
R = int(input("Radio: "))

A = 2 * pi  * R(h + R)
V = pi * R**2 * h
print("Formula Area:  2 * pi  * R(h + R),\t Formula Volumen: pi * R^2 * h")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
from math import pi
print("\n~~~~~~~~~~~~~~~~~Tronco de Cono~~~~~~~~~~~~~~~~~")
h = int(input("Altura: "))
g = int(input("Generatriz: "))
R = int(input("Radio Base Mayor: "))
r = int(input("Radio Base Menor: "))

A = pi * (g*(R+r) + r**2 + R**2)
V = (pi * h * (R**2 + R*r + r**2)) / 3
print("Formula Area:  pi * (g*(R+r) + r^2 + R^2),\t Formula Volumen: (pi * h * (R^2 + R*r + r^2)) / 3")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
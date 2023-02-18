from math import pi
print("\n~~~~~~~~~~~~~~~Casquete Esferico~~~~~~~~~~~~~~~~")
R = int(input("Radio: "))
h = int(input("Altura: "))

A = 2 * pi * R * h
V = (pi*h**2*((3*R-h))/3)
print("Formula Area:  2 * pi * R * h,\t Formula Volumen: (pi*h^2*((3*r-h))/3)")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
from math import pi
print("\n~~~~~~~~~~~~~~Huso: Cuña Esferica~~~~~~~~~~~~~~~")
R = int(input("Radio: "))
n = int(input("Angulo del sector: "))

A = (4*pi * R**2 * n) / 360
V = (4*pi * R**3 * n) / (3*360)  
print("Formula Area:  (4*pi * R^2 * n) / 360,\t Formula Volumen: (4*pi * R^3 * n) / (3*360)")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
from math import pi
print("\n~~~~~~~~~~~~~~~~Sector Circular~~~~~~~~~~~~~~~~~")
R = int(input("Radio: "))
n = int(input("Angulo del sector: "))

A = (pi * R**2 * n) / 360
print("Formula Area:  (pi * R^2 * n) / 360")
print("A = ", A)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
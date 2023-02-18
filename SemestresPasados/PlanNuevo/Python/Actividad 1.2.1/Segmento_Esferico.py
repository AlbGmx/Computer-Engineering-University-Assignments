from math import pi
print("\n~~~~~~~~~~~Zona o Segmento de Esfera~~~~~~~~~~~~")
R = int(input("Radio Mayor: "))
r = int(input("Radio Menor: "))
h = int(input("Altura del segemnto: "))

A = 2 * pi * R * h
V = ((pi*h*(h**2+3*R**2+r*3**2))/3)
print("Formula Area:  2 * pi * R * h,\t Formula Volumen: ((pi*h*(h^2+3*R^2+r*3^2))/3)")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
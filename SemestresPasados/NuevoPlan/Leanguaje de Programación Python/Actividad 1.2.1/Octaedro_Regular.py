from math import sqrt
print("\n~~~~~~~~~~~~~~~~Octaedro Regular~~~~~~~~~~~~~~~~")
a = int(input("Lado: "))

A = 2 * (sqrt(3) * a**2)
V = (sqrt(2) * a**3) / 3
print("Formula Area:  2 * (sqrt(3) * a^2),\t Formula Volumen: (sqrt(2) * a^3) / 3")
print("A = ", A, ",\tV= ", V)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
print("\n~~~~~~~~~~~~~~~~~~Prisma Recto~~~~~~~~~~~~~~~~~~")
h = int(input("Altura: "))
a = int(input("Apotema: "))
Ab = int(input("Area Base: "))
n = int(input("Numero de lados: "))

P = n * a
A = P * ( h + a)
V = Ab * h
print("Formula Area:  P * ( h + a),\t Formula Volumen: Ab * h")
print("A = ", A, ",\tV= ", P)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def main():
   file = open("Estudiantes.txt", "w")
   students = int(input("Ingrese el numero de estudiantes: "))
   for i in range(students):
      print("Ingrese los datos del estudiante ", i+1)
      name = input("Ingrese el nombre: ")
      id = input("Ingrese la matricula: ")
      file.write(name + " " + id + "\n")

   file.close()

   file = open("Estudiantes.txt", "r")
   print("Los estudiantes son: ")
   for line in file:
      print(line)
      
   file.close()

if __name__ == "__main__":
   main()
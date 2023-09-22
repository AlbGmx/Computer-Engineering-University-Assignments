import os
import random
import string 

def main():
   clear()
   board = []
   pairsFlipped = 0
   for i in range(4):
      board.append([])
      for j in range(5):
         #Agregamos una letra al azar de la a minuscula a la Z mayuscula para disminuir la probabilidad de que se repitan
         board[i].append(random.choice(string.ascii_letters))

   #Generamos los pares
   for i in range(4):
      for j in range(5):
         #Creamos una pareja y la insertamos en una posicion aleatoria
         board[random.randint(0,3)][random.randint(0,4)] = board[i][j]

   print("Bienvenido al juego de Memorama")
   print("Instrucciones: Se te mostrara un tablero con 20 letras, debes encontrar las parejas de cada letra")
   print("Para seleccionar una letra, debes ingresar la fila y la columna de la letra que deseas seleccionar")
   print("Empezando desde la fila 0 y columna 0")
   print("Antes de seleccionar un par, se mostrara el tablero de forma indefinida antes de ocultarlo")
   print("Para salir del juego, ingresa -1 en la fila y,o columna de cualquier carta")
   print("Buena suerte!")
   print()
   tries = int(input("Ingrese el numero de intentos: "))
   for i in range(tries):
      print("\n\nTablero:")
      printBoard(board)
      input("\nIntento "+ str(i+1) +  "\nPresione enter para continuar")
      clear()
      print("intento " + str(i+1) + " de " + str(tries))
      print("Adivine la primera carta")
      row1 = int(input("Renglon (0-3): "))
      col1 = int(input("Columna (0-4): "))

      print("Adivine la pareja de la carta")
      row2 = int(input("Renglon (0-3): "))
      col2 = int(input("Columna (0-4): "))
      if(row1 == -1 or col1 == -1 or row2 == -1 or col2 == -1):
         break
      elif board[row1][col1] == board[row2][col2]:
         if row1 == row2 and col1 == col2:
            print("\nNo puedes elegir la misma carta!!")
         elif ((board[row1][col1] == 0 and board[row2][col2] == 0)): print("\nEsa pareja ya fue encontrada!")
         else:
            print("\nAdivinado!")
            pairsFlipped += 1
            board[row1][col1] = 0
            board[row2][col2] = 0
      else:
         print("\nIntente de nuevo")

      print("\nIntentos restantes: ", tries - i - 1)
      print("Pares encontrados: ", pairsFlipped)

      if board == [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]:
         print("\n\nFelicidades, ha ganado!")
         printBoard(board)
         break

def clear():
   os.system('cls' if os.name == 'nt' else 'clear')

def printBoard(board):
   for i in range(4):
      for j in range(5):
         print(board[i][j], end = " ")
      print()

if __name__ == "__main__":
   main()

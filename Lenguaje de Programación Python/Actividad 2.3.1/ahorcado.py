import random
import os

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def ahorcado():
    words = ["assembly", "basic", "c", "c++", "c#", "cobol", "fortran", "java", "javascript", "lisp", "pascal", "perl", "php", "python", "ruby", "swift", "visualbasic"]

    word = random.choice(words)
    word = word.lower()
    word = list(word)
    wordLength = len(word)
    wordHidden = []
    for i in range(wordLength):
        wordHidden.append("_")
    clear()
    print("Bienvenido al juego del ahorcado de lenguajes de programacion")
    print("Instrucciones: Se te mostrara el numero de letras que contiene la palabra, debes adivinarla letra por letra")
    print("Para seleccionar una letra, debes ingresar la letra que deseas seleccionar")
    print("Para salir del juego, ingresa -1")
    print("Buena suerte!")
    tries = 20
    for i in range(tries):
        print("\n\nPalabra:")
        print(wordHidden)
        print("Intento " + str(i+1) + " de " + str(tries))
        print("Adivine la letra")
        letter = str(input("Letra: ")).lower()
        clear()
        if(letter == "-1"):
            break
        #si la letra ya fue adivinada cuenta como intento fallido
        elif letter in wordHidden:
            print("\nEsa letra ya fue adivinada!")
        elif letter in word:
            print("\nAdivinado!", i)
            for j in range(wordLength):
                if letter == word[j]:
                    wordHidden[j] = letter
        else:
            print("\nIntente de nuevo")

        if wordHidden == word:
            print("Felicidades, has ganado!")
            print("La palabra es: ", word)
            return
    clear()
    print("Has perdido, la palabra era: " + "".join(word))

ahorcado()
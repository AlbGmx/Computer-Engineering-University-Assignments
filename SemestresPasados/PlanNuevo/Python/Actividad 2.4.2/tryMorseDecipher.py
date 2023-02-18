def morse2Text(morse):
    morse_code = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.',
                  'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
                  'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---',
                  'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
                  'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--',
                  'Z': '--..', '1': '.----', '2': '..---', '3': '...--',
                  '4': '....-', '5': '.....', '6': '-....', '7': '--...',
                  '8': '---..', '9': '----.', '0': '-----'}
    morse_text = ''
    temp = ''
    flag = False
    for i in range(len(morse)):
        if morse[i] == '.' or morse[i] == '-':
            temp += morse[i]
            flag = True
        elif morse[i] == ' ':  # si es un espacio
                if morse[i-1] == ' ':
                    morse_text += ' '
                elif flag:
                    morse_text += list(morse_code.keys()
                                   )[list(morse_code.values()).index(temp)]
                    flag = False
                    temp = ''
        else:
            try:
                morse_text += list(morse_code.keys()
                               )[list(morse_code.values()).index(temp)]
                flag = False
                temp = ''
            except ValueError:
                print("\n\nError: Caracter: '" + morse[i] + "' no valido")
                return
    if flag:
        morse_text += list(morse_code.keys()
                           )[list(morse_code.values()).index(temp)]

    return morse_text

morse = " .-.. . -. --. ..- .- .--- .  -.. .  .--. .-. --- --. .-. .- -- .- -.-. .. --- -.  .--. -.-- - .... --- -. "
print("\n\nEntrada correcta \nCodigo a decifrar: " + morse + "\nCodigo decifrado: " + morse2Text(morse))

morse = "Este es un mensaje de prueba de error"
print("\n\nEntrada incorrecta \nCodigo a decifrar: " + morse + "\nCodigo decifrado: ", end='')
print(morse2Text(morse))

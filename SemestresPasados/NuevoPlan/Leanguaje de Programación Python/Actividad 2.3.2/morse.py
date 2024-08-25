def morse(text):
    morse_code = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.',
                  'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
                  'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---',
                  'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
                  'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--',
                  'Z': '--..', '1': '.----', '2': '..---', '3': '...--',
                  '4': '....-', '5': '.....', '6': '-....', '7': '--...',
                  '8': '---..', '9': '----.', '0': '-----'}
    morse_text = ''
    for letter in text:
        if letter != ' ':
            morse_text += morse_code[letter] + ' '
        else:
            morse_text += ' '
    return morse_text

text = "Lenguaje de Programacion Python"
result = morse(text.upper())
print("text: " + text + "\n" + "Resultado: " + result)

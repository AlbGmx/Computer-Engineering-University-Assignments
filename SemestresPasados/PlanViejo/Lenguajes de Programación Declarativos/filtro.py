def vocales(variable): 
    letras = ['a', 'e', 'i', 'o', 'u'] 
    if (variable in letras): 
        return True
    else: 
        return False

secuencia = ['p', 'y', 't', 'h', 'o', 'n'] 
  
filtered = filter(vocales, secuencia) 
  
print('The filtered letters are:') 
for s in filtered: 
    print(s) 
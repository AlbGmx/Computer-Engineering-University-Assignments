# Capturar entero
def getInt(str):
    return int(input(str + ": "))
# Capturar flotante
def getFloat(str):
    return float(input(str + ": "))
# Capturar string
def getStr(str):
    return str(input(str + ": "))

# Reutilizacion de codigo de la practica de Matrices
def createMat(size):
    # Crea e inicializa la matriz con 0's flotantes
    mat = [[float(0) for j in range(size)] for i in range(size)]
    # inicializa la matriz de respuestas con 0's flotantes
    b = [float(0) for i in range(size)]
    for i in range(size):
        for j in range(size):
            mat[i][j] = getFloat("coeficiente de x^" + str(j) + " de la ecuacion " + str(1+i))
    #Resultados de la ecuacion
    for i in range(size):
        b[i] = getFloat("Resultado de la ecuacion " + str(1+i))

    return mat, b

#Comprueba que los coeficientes a11, b22 y c33 sean los mas grandes de las ecuaciones respectivas
def comprobations(coef):
    size = len(coef[0])
    temp = 0
    status = False
    for i in range(size):
        for j in range(size):
            if ((j == i) or (j == 0)):
                if (j!=i):
                    temp+= coef[i][j]
                else:
                    pass
            elif (i > j):
                temp += coef[i][i-j]
            else:
                temp += coef[i][j]
        if ( (coef[i][i] >= temp) ):
            status = True
        else:
            return False
        temp=0
    return status

# Imprimir el encabezado de una lista de n ecuaciones
def printHeader(size):
    print("{:>10}".format("Iteracion"), end = "")
    for i in range(size):
            print("{:>27}".format("x" + str(1+i)), end = "")
    print("{:>27}".format("Porcentaje de error"))

# Imprimir tabla
def printTable(rep, x, aproxError, size, final):
    if(True == final):
        print("--Resultados", end="")
        for i in range(size*42):
            print("-", end="")
        print("\n{:>10}".format(""), end = "")
        for i in range(size):
            print("{:>27}".format(round(x[i],6)), end = "")
        print("{:27}".format(round(aproxError,6)))
    else: 
        print("{:>10}".format(rep), end = "")
        for i in range(size):
            print("{:>27}".format(x[i]), end = "")
        print("{:27}".format(aproxError))

# Sustituye e imprime los valores en sus respectivas ecuaciones
def CheckAns (eq, x, res):
    size = len(x)
    temp = [float(0) for i in range(size)]
    flag = True

    for i in range(size):
        print("\n\tecuacion " + str(i+1) + " = ", end="")
        for j in range(size):
            if( j==0):
                print(str(eq[i][j]*x[j]), end = "")
            else:
                print(" + " + str(eq[i][j]*x[j]), end = "")
            temp[i] += eq[i][j]*x[j]
        print(" = ", str(temp[i]))
        if( round(temp[i],6) != round(res[i],6) ):
            flag = False
    return flag
        

# Metodo Jacobi
def Jacobi (eq, res, iterations, error):
    aproxError = 100
    size = len(eq[0])
    temp = [float(0) for i in range(size)]
    aux = 0
    x = [float(0) for i in range(size)]
    xOld = float(0)
    rep = 0
    printHeader(size)
    printTable(rep,x,aproxError, size, False)
    rep += 1
    # El programa se detendrá si se llegan a las iteraciones determinadas, al error aproximado deseado 
    # o si han pasado 3000 iteraciones y aun no se cumple ninuna de las anteriores
    while((iterations != 0) & (aproxError > error) & (rep < 3000)):  

        for i in range(size):
            for k in range(size):
                if (i == k):
                    pass
                else:
                    aux += eq[i][k] * x[k]
            temp[i] = (res[i] - aux)/eq[i][i]
            aux = 0

        if (rep != 1):
            aproxError = abs(((x[0] - xOld) / x[0])*100)
        xOld = x[0]

        for i in range(size):
            x[i] = temp[i]

        printTable(rep,x,aproxError, size, False)
        iterations -= 1
        rep += 1
    return x

#Gauss Seidel
def GaussSeidel (eq, res, iterations, error):
    aproxError = 100
    size = len(eq[0])
    temp = [float(0) for i in range(size)]
    aux = 0
    x = [float(0) for i in range(size)]
    xOld = float(0)
    rep = 0
    printHeader(size)
    printTable(rep,x,aproxError, size, False)
    rep += 1
    # El programa se detendrá si se llegan a las iteraciones determinadas, al error aproximado deseado 
    # o si han pasado 3000 iteraciones y aun no se cumple ninuna de las anteriores
    while((iterations != 0) & (aproxError > error) & (rep < 3000)):  

        for i in range(size):
            for k in range(size):
                if (i == k):
                    pass
                else:
                    aux += eq[i][k] * x[k]
            x[i] = (res[i] - aux)/eq[i][i]
            aux = 0

        if (rep != 1):
            aproxError = abs(((x[0] - xOld) / x[0])*100)
        xOld = x[0]


        printTable(rep,x,aproxError, size, False)
        iterations -= 1
        rep += 1
    return x

size = getInt("introduzca el numero de ecuaciones")
temp = createMat(size)
eqInMatixForm = temp[0]
res = temp[1]
if (comprobations(eqInMatixForm) == False):
    print("La ecuacion puede no converger a una solucion correcta")
    ans = str(input("Desea continuar? S/N: "))
    if (ans == "S" or ans == "s"):
        pass
    else:
        quit()
iterations = getInt("Introduzca el numero de iteraciones a realizar (-1 para indefinidas)")
error = getFloat("Introduzca el porcentaje de error permitido (0 para buscar el valor exacto)")
x = Jacobi(eqInMatixForm, res, iterations, error)
if ( CheckAns (eqInMatixForm, x, res) == True):
    print("\nEl resultado satisface la ecuacion\n")
else:
    print("\nEl resultado no satisface la ecuacion\n")
y = GaussSeidel(eqInMatixForm, res, iterations, error)
if ( CheckAns (eqInMatixForm, x, res) == True):
    print("\nEl resultado satisface la ecuacion\n")
else:
    print("\nEl resultado no satisface la ecuacion\n")
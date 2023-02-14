#Capturar entero
def getInt(str):
  return int(input(str + ": "))

#Capturar flotante
def getFloat(str):
  return float(input(str + ": "))

#Metodo NewtonRaphson2doOrden
def NewtonRaphson2doOrden(equation, start, error, iterations):
  aproxError = 100
  xOld = 0
  fx = 0
  fdx = 0
  fddx = 0
  x = 0
  i = 1
  print("-----------------------------------------------------------------------------------------------------------------------")
  print("{:>4} {:>25} {:>25} {:>25} {:>25}".format(
      "Iteraciones", "f(x)", "f'(x)", "f''(x)", "Error Aproximado"))
  print("------------------------------------------------------------------------------------------------------------------------")
  x = start
  while((iterations != 0) & (aproxError > error)):
    fx = evaluateFunction(equation, x)
    fdx = evaluateFunction(derivada(equation), x)
    fddx = evaluateFunction(derivada(derivada(equation)), x,)
    if ((fdx == 0) | (fx == 0) | (fddx == 0)):
      return x
    x = x-((fdx*fx)/((fdx**2)-(fx*fddx)))
    if (i == 1):
      pass
    else:
      aproxError = abs(((x - xOld) / x)*100)
    xOld = x
    print("{:>4} {:>32} {:>25} {:>25} {:>25}".format(i, fx, fdx, fddx, aproxError))
    i = i + 1
    iterations=iterations-1
  return x

#Obtener derivada de una funcion dada
def derivada(equation):
  res = []
  for k in range(len(equation)):
    if (k == 0):
      pass
    #2x^2+3x-1
    else:
     res.append(k * equation[k])
  return res
    
#Evalua la ecuacion proporcionada en el numero deseado
def evaluateFunction(equation, number):
  res = 0
  for j in range(len(equation)):
    res += (equation[j] * (number ** (j)))
  return res


g = 1 + getInt("Introduzca numericamente el grado de su ecuacion")
if(g<3):
  print("La funcion necesita sere de minimo 2do grado")
else:
  equation = []
  root = 0
  for i in range(g):
    equation.append(getFloat("Coeficiente del termino x^" + str(i)))
  start = getFloat("Introduzca el valor de inicio")
  error = getFloat("Porcentaje de error maximo permitido (0 para buscar raiz exacta)")
  iterations = getFloat("Iteraciones (-1 para indefinido)")
  root = NewtonRaphson2doOrden(equation, start, error, iterations)
  print("\n\n\tRaiz obtenida utilizando el metodo de Newton-Raphson: ", root )
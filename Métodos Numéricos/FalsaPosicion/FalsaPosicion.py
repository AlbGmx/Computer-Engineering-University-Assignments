#Capturar entero
def getInt(str):
  return int(input(str + ": "))

#Capturar flotante
def getFloat(str):
  return float(input(str + ": "))

#Evalua la ecuacion proporcionada en el numero deseado
def evaluateFunction(equation, number):
  res = 0
  for j in range(len(equation)):
    res += (equation[j] * (number ** (j)))
  return res

#Metodo de falsa posicion
def falsePos(equation, a, b, iterations, error):
  aproxError = 100
  xs = 0
  xsa = 0
  i = 1
  if((evaluateFunction(equation, a)*evaluateFunction(equation, b)) >= 0):
    return ("\n\n\tNo existe raiz en el intervalo indicado")
  print("-------------------------------------------------------------------------------------------------------------")
  print("{:>4} {:>18} {:>25} {:>25} {:>25}".format(
      "Iteraciones", "a", "b", "xs", "Error Aproximado"))
  print("-------------------------------------------------------------------------------------------------------------")
  while((iterations != 0) & (aproxError > error)):
    fa = 0
    fxs = 0
    fa = evaluateFunction(equation, a)
    fb = evaluateFunction(equation, b)
    xs = ((a*fb)-(b*fa))/(fb-fa)
    fxs = evaluateFunction(equation, xs)
    aproxError = abs(((xs - xsa) / xs)*100)
    xsa = xs
    print("{:>4} {:>25} {:>25} {:>25} {:>25}".format(i, a, b, xs, aproxError))
    if (fa * fxs > 0):
      a = xs
    elif (fa * fxs < 0):
      b = xs
    elif (fa * fxs == 0):
      break
    iterations = iterations - 1
    i = i + 1
  return xs

#funcion main
g = 1 + getInt("Introduzca numericamente el grado de su ecuacion")
equation = []
for i in range(g):
  equation.append(getFloat("Coeficiente del termino x^" + str(i)))
start = getInt("Valor inicial (a)")
end = getInt("Valor final (b)")
iterations = getInt("Iteraciones a realizar (-1 para indeterminado)")
error = getFloat("Porcentaje de error permitido (0 para buscar raiz exacta)")
rootFalsePos = falsePos(equation, start, end, iterations, error)
print("\n\n-------------------------------------------------------------------------------------------------------------")
print("\tRaiz aproximada usando el metodo de falsa posicion: ", rootFalsePos)
print("-------------------------------------------------------------------------------------------------------------")

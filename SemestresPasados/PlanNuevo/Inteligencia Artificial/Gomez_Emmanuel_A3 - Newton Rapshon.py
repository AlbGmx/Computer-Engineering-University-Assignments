def f(x):
    return -2*x + x**3


def f_derivada(x):
    return -2 + 3*x**2


def newton_raphson(x_old, tol=1e-6, max_iter=100):
    for i in range(max_iter):
        x_n = x_old - (f(x_old)/f_derivada(x_old))
        x_old = x_n
        if f(x_old) < tol:
            return x_old


# Probrar con valor inicial 2
x0 = float(input("Ingrese una aproximacion inicial: "))
raiz = newton_raphson(x0)
print("La raíz es aproximadamente:", raiz)

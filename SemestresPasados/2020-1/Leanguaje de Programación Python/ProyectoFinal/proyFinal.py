import argparse
import math


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument("operacion", choices=[
                        "suma", "resta", "multiplicacion", "division", "potencia", "raiz_cuadrada", "factorial", "modulo"], help="Operacion aritmetica a realizar")
    parser.add_argument("operando1", type=int, help="Primer operando")
    parser.add_argument("operando2", type=int, nargs='?',
                        default=None, help="Segundo operando")
    parser.add_argument("--formato_salida", choices=[
                        "decimal", "binario", "hexadecimal"], help="Formato de salida para el resultado")
    parser.add_argument("--precision", type=int,
                        help="Numero de decimales a redondear el resultado")

    args = parser.parse_args()

    if args.operacion == "suma":
        resultado = args.operando1 + args.operando2
    elif args.operacion == "resta":
        resultado = args.operando1 - args.operando2
    elif args.operacion == "multiplicacion":
        resultado = args.operando1 * args.operando2
    elif args.operacion == "division":
        if args.operando2 == 0:
            raise ValueError("No se puede dividir por cero")
        resultado = args.operando1 / args.operando2
    elif args.operacion == "potencia":
        resultado = args.operando1 ** args.operando2
    elif args.operacion == "raiz_cuadrada":
        if args.operando1 < 0:
            raise ValueError(
                "No se puede obtener la raiz cuadrada de un numero negativo")
        resultado = math.sqrt(args.operando1)
    elif args.operacion == "factorial":
        if args.operando1 < 0:
            raise ValueError(
                "No se puede calcular el factorial de un numero negativo")
        resultado = math.factorial(args.operando1)
    elif args.operacion == "modulo":
        if args.operando2 == 0:
            raise ValueError("No se puede dividir por cero")
        resultado = args.operando1 % args.operando2

    if args.precision is not None:
        resultado = round(resultado, args.precision)

    if args.formato_salida == "binario":
        resultado_str = "{0:b}".format(resultado)
    elif args.formato_salida == "hexadecimal":
        resultado_str = "{0:x}".format(resultado)
    else:
        resultado_str = str(resultado)

    print(resultado_str)


if __name__ == "__main__":
    try:
        main()
    except ValueError as e:
        print

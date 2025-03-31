import math
b=1
r1=0
r2=0
i1=0
i2=0

while b:
    print("a: ", end ='')
    a = int(input())
    print("b: ", end ='')
    b = int(input())
    print("c: ", end ='')
    c = int(input())
    print('\n\n')
    if a==0 :
        if b!=0:
            r1 = -c/b
        else: 
            print("Solucion Trivial")
    else:
        discr = ((b**2) - (4*a*c))
        if discr >= 0:
            r1 =( (-b + math.sqrt(discr)) / (2*a) )
            r2 =( (-b - math.sqrt(discr)) / (2*a) )
        else:
            r1 = -b/(2*a)
            r2 =r1
            i1 = ( math.sqrt(abs(discr)) / (2*a) )
            i2 = -i1

    print("r1: ",  r1)
    print("r2: ",  r2)
    print("i1: ",  i1)
    print("i2: ",  i2)
    x=input("¿Repetir? (s/n) ")
    if x=='s':
        b=1
    else:
        b=0

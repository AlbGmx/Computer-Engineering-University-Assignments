def main():
   a = int(input("Ingrese el valor de a: "))
   b = int(input("Ingrese el valor de b: "))

   print("a) ((3+5*8)<3 and ((-6/3*4)+2<2)) or (a>b) is: ",
         ((3+5*8) < 3 and ((-6/3*4)+2 < 2)) or (a > b))
   print("\nb) ((2+5*7)>3 or ((-5/7*5)+2>2)) and (a<b) is: ",
         ((2+5*7) > 3 or ((-5/7*5)+2 > 2)) and (a < b))
   print("\nc) ((4+5*6)<=3 or not ((-4/6*6)+2<=2)) or (a>=b) is: ",
         ((4+5*6) <= 3 or not ((-4/6*6)+2 <= 2)) or (a >= b))
   print("\nd) ((6-5*5)>=3 and ((-3/5*7)+2>=2)) or not (a<=b) is: ",
         ((6-5*5) >= 3 and ((-3/5*7)+2 >= 2)) or not (a <= b))
   print("\ne) ((8-5*4)<3 and ((-2/4*8)+2<2)) and (a==b) is: ",
         ((8-5*4) < 3 and ((-2/4*8)+2 < 2)) and (a == b))
   print("\nf) ((3-5*3)>3 or ((-1/3*9)+2>2)) or (a!=b) is: ",
         ((3-5*3) > 3 or ((-1/3*9)+2 > 2)) or (a != b))

if __name__ == "__main__":
   main()

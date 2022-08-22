from re import I


odd= lambda x:3*x+1
even= lambda x:x/2
def collatz(n):
   count=1
   while n!=1:
    count+=1
    if n%2==0:
        n= even(n)
    else:
        n= odd(n)
   return count

def _main_():
   max=0
   maxi=0
   for i in range(0,1000000):
      coll=collatz(i)
      if(coll>max):
         maxi=i
         max=coll
         print(maxi,max)

_main_()


def smallestMultiple(n):
   i = 1
   while True:
      for j in range(1, n+1):
         if i % j != 0:
            break
      else:
         return i
      i += 1


print(smallestMultiple(20))

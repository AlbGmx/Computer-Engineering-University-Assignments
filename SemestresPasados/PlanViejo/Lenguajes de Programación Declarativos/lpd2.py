from functools import reduce
  
Fibonacci = lambda n: reduce(lambda x, _: x+[x[-1]+x[-2]], range(n-2), [0, 1]) 

for i in Fibonacci(10):
    print(i)
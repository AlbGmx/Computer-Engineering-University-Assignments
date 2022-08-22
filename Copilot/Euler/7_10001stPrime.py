def findPrime(n):
    while True:
        if isPrime(n):
            return n
        n += 1
    
def isPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
    
print(findPrime(6))
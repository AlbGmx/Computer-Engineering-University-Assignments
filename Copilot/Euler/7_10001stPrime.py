def findPrime3_N(n):
    counter = 2
    i = 3
    while counter <= n:
        if isPrime(i):
            counter += 1
        i += 2
    return i - 2

def isPrime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

print(findPrime3_N(10001))
from math import gcd

def F(a, b, c):
    return (a * b * c) // (4 * gcd(a, b, c)**2)

def G(n):
    s = 0
    for a in range(9, n - 2):
        for b in range(a + 1, n - 1):
            for c in range(b + 1, n):
                s += F(a, b, c)
    return s

print(G(53))

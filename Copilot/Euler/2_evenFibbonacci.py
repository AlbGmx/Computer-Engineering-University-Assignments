def SumEven(n):
    sum = 0
    val1 = 1
    val2 = 2
    for i in range(n):
        if val2 % 2 == 0:
            sum += val2
        temp = val2
        val2 += val1
        val1 = temp
    return sum


print(SumEven(33))



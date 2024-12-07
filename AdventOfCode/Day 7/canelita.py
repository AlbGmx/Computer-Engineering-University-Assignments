import re
import time

with open("input.txt") as f:
    s = f.read().strip()

(
    ans_1,
    ans_2,
) = 0, 0

l = s.split("\n")
values = re.findall(r"\d+:", s)
for i in range(len(values)):
    values[i] = values[i].replace(":", "")
values = [int(value) for value in values]

numbers = []
numbers_temp = []
for x in l:
    numbers_temp.append(re.findall(r"\b\d+\b(?!:)", x))

for number in numbers_temp:
    numbers.append([int(numb) for numb in number])


def run():
    for i in range(len(values)):
        op = 0b00
        mask = 0b11
        for x in range(pow(3, len(numbers[i]) - 1)):
            res = numbers[i][0]
            for j in range(1, len(numbers[i])):
                if (op >> ((j - 1) * 2)) & mask == 0:
                    res += numbers[i][j]
                elif (op >> ((j - 1) * 2)) & mask == 1:
                    res *= numbers[i][j]
                elif (op >> ((j - 1) * 2)) & mask == 2:
                    res = int(str(res) + str(numbers[i][j]))
            if res == values[i]:
                break
            op += 1
            if op & mask == 3:
                op += 1
                z = 1
                while (op >> (z * 2)) & mask == 3:
                    op += 1 << (z * 2)
                    z += 1


avg_time = []
for _ in range(5):
    start_time = time.time()
    run()
    end_time = time.time()
    avg_time.append(end_time - start_time)

print(f"Canelita: \t{sum(avg_time)/len(avg_time)}")


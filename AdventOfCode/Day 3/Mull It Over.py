import re

filename = 'input.txt'

with open(filename, 'r') as file:
    corrupted_memory = file.read().strip() 
    
mul_pattern = r'mul\((\d+),(\d+)\)'
matches = re.findall(mul_pattern, corrupted_memory)

print(f'Sum = {sum(int(x) * int(y) for x, y in matches)}')

### Part Two ###
do_pattern = r'do\(\)'
dont_pattern = r"don't\(\)"

enabled = True  
matches = []

index = 0
while index < len(corrupted_memory):
    if corrupted_memory[index:index+4] == 'mul(':
        mul_match = re.match(mul_pattern, corrupted_memory[index:])
        if mul_match:
            x, y = mul_match.groups()
            if enabled:
                matches.append((int(x), int(y)))
            index += len(mul_match.group(0))
        else:
            index += 1
    elif corrupted_memory[index:index+4] == 'do()':
        enabled = True
        index += 4
    elif corrupted_memory[index:index+7] == "don't()":
        enabled = False
        index += 7
    else:
        index += 1

print(f'Total sum with conditions = {sum(x * y for x, y in matches)}')
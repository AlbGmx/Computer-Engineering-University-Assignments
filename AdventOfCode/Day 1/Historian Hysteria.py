puzzle_input_path = "input.txt"

with open(puzzle_input_path, 'r') as file:
   data = file.readlines()

left_list = []
right_list = []

for line in data: 
   left, right = map (int, line.strip().split())
   left_list.append(left)
   right_list.append(right)

left_list.sort()
right_list.sort()
print(f'\tTotal distance between lists: {sum(abs(l - r) for l, r in zip(left_list, right_list))}')

### Part Two ###
from collections import Counter

right_freq = Counter(right_list)
print(f'\tSimilarity score: {sum(num * right_freq.get(num, 0) for num in left_list)}')

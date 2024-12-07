filename = "input.txt"

with open(filename, "r") as file:
   data = file.read()

section1, section2 = data.split("\n\n")
section1 = section1.split("\n")

conditions = []
for pair in section1:
   # print(x,y)
   x,y = map(int, pair.split("|"))
   conditions.append((x,y))

section2 = [list(map(int, update.split(","))) for update in section2.strip().split("\n")]

def check_rules(rules, update):
   incorrect_found = False  
   while True:  
      applicable_rules = [(x, y) for x, y in rules if x in update and y in update]
      positions = {page: idx for idx, page in enumerate(update)}
      
      changed = False
      for x, y in applicable_rules:
         if positions[x] > positions[y]:  
            ### Part 2 ###
            print(f'Incorrect update: {update}, rule: {positions[x]} > {positions[y]}')
            update.insert(positions[y], update.pop(positions[x]))
            # print(f'Corrected update: {update}\n')
            changed = True 
            incorrect_found = True 
            break
            
      if not changed:
         break

   return not incorrect_found

correct_pages = []
incorrect_pages = []
for update in section2:
   # print(f'Checking update: {update}')
   if check_rules(conditions, update):
      # print(f'No change')
      correct_pages.append(update[len(update) // 2])
   else:
      # print(f'Change made')
      # print(f'Corrected update: {update}\n') 
      incorrect_pages.append(update[len(update) // 2])

print(f'Sums: {sum(correct_pages)}, {sum(incorrect_pages)}')
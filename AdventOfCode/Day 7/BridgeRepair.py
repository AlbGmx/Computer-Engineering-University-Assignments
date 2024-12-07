import time

filename = "input.txt"

with open(filename, "r") as file:
    data = file.readlines()

parsed_data = []
for row in data:
    row.strip()
    test_value, values = row.split(":")
    values = values.split()
    values = [int(value) for value in values]
    parsed_data.append((int(test_value), values))


def increment_array(array):
    carry_flag = False
    array[0] += 1
    if array[0] == 3:
        array[0] = 0
        carry_flag = True
    if not carry_flag:
        return
    for index in range(1, len(array)):
        if carry_flag:
            array[index] += 1
            carry_flag = False
        if array[index] == 3:
            array[index] = 0
            carry_flag = True
        if not carry_flag:
            return


counter_sum = 0
counter_mul = 0
counter_concat = 0
def evaluate_possible_equation(test_value, values):
    array = [0] * (len(values) - 1)
    for _ in range(pow(3, (len(values) - 1))):
        total = values[0]
        for index in range(1, len(values)):
            if array[index - 1] == 0:
                total += values[index]
            elif array[index - 1] == 1:
                total *= values[index]
            else:
                total = int(str(total) + str(values[index]))
        increment_array(array)
        if total == test_value:
            return True
    return False


correct_equations = []
avg_time = []
for _ in range(5):
    start_time = time.time()
    for test_value, values in parsed_data:
        if evaluate_possible_equation(test_value, values):
            correct_equations.append((test_value))
    end_time = time.time()
    avg_time.append(end_time - start_time)

print(f"Yo: \t\t{sum(avg_time)/len(avg_time)}")

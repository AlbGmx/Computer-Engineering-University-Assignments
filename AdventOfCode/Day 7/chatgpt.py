import time

filename = "input.txt"

def process_file(filename):
    with open(filename, "r") as file:
        for line in file:
            test_value, values = line.strip().split(":")
            yield int(test_value), list(map(int, values.split()))

def evaluate_possible_equation(test_value, values):
    n = len(values) - 1
    max_state = 3**n
    for state in range(max_state):
        total = values[0]
        current_state = state
        for i in range(n):
            op = current_state % 3  # Extraer la operación actual (0, 1, 2)
            current_state //= 3
            if op == 0:  # Suma
                total += values[i + 1]
            elif op == 1:  # Multiplicación
                total *= values[i + 1]
            else:  # Concatenación aritmética
                total = total * (10**len(str(values[i + 1]))) + values[i + 1]
        if total == test_value:
            return True
    return False

# Evaluar las ecuaciones y medir el tiempo promedio
avg_time = []
for _ in range(5):
    start_time = time.time()
    correct_equations = [
        test_value for test_value, values in process_file(filename)
        if evaluate_possible_equation(test_value, values)
    ]
    end_time = time.time()
    avg_time.append(end_time - start_time)

print(f"Tiempo promedio: {sum(avg_time) / len(avg_time):.6f} segundos")

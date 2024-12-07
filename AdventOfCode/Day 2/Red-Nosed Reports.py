puzzle_input_path = "input.txt"

with open(puzzle_input_path, 'r') as file:
    reports = [list(map(int, line.strip().split())) for line in file.readlines()]

def is_safe(report):
    differences = [report[i + 1] - report[i] for i in range(len(report) - 1)]
    
    is_increasing = all(0 < diff <= 3 for diff in differences)
    is_decreasing = all(-3 <= diff < 0 for diff in differences)
    
    return is_increasing or is_decreasing

print(f'\tSafe reports: {sum(1 for report in reports if is_safe(report))}')

### Part Two ###

def is_safe_with_dampener(report):
    if is_safe(report):
        return True
    
    for i in range(len(report)):
        modified_report = report[:i] + report[i+1:]
        if is_safe(modified_report):
            return True
    
    return False

print(f'\tSafe reports: {sum(1 for report in reports if is_safe_with_dampener(report))}')

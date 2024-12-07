filename = "input.txt"

with open(filename, "r") as file:
    grid = file.readlines()

word_to_find = "XMAS"
total_occurrences = 0
word_length = len(word_to_find)
number_of_rows = len(grid)
number_of_columns = len(grid[0])


def matches_word(start_row, start_column, row_step, column_step):
    for letter_position in range(word_length):
        current_row = start_row + letter_position * row_step
        current_col = start_column + letter_position * column_step
        if not (
            (0 <= current_row < number_of_rows)
            and (0 <= current_col < number_of_columns)
        ):
            return False
        if grid[current_row][current_col] != word_to_find[letter_position]:
            return False
    return True


for row in range(number_of_rows):
    for column in range(number_of_columns):
        if matches_word(row, column, 0, 1):  # Right
            total_occurrences += 1
        if matches_word(row, column, 0, -1):  # Left
            total_occurrences += 1
        if matches_word(row, column, 1, 0):  # Down
            total_occurrences += 1
        if matches_word(row, column, -1, 0):  # Up
            total_occurrences += 1
        if matches_word(row, column, 1, 1):  # Diagonal down-right
            total_occurrences += 1
        if matches_word(row, column, 1, -1):  # Diagonal down-left
            total_occurrences += 1
        if matches_word(row, column, -1, 1):  # Diagonal up-right
            total_occurrences += 1
        if matches_word(row, column, -1, -1):  # Diagonal up-left
            total_occurrences += 1

print(f'Total occurrences of "{word_to_find}" in the grid: {total_occurrences}')

### Part Two ###

x_mas_count = 0


def matches_x_mas(center_row, center_col):
    directions = [
        ((-1, -1), (1, 1)),  # Top
        ((-1, 1), (1, -1)),  # Right
        ((1, -1), (-1, 1)),  # Left
        ((1, 1), (-1, -1)),  # Bottom
    ]
    i = 0
    for x, y in directions:
        if (
            grid[center_row + x[0]][center_col + x[1]] == "M"
            and grid[center_row + x[1]][center_col + y[0]] == "M"
            and grid[center_row + y[0]][center_col + y[1]] == "S"
            and grid[center_row + y[1]][center_col + x[0]] == "S"
        ):
            return True
        i += 1
    return False


for row in range(1, number_of_rows - 1):
    for column in range(1, number_of_columns - 1):
        if grid[row][column] == "A":
            if matches_x_mas(row, column):
                x_mas_count += 1

print(f'Total occurrences of "X-MAS" in the grid: {x_mas_count}')

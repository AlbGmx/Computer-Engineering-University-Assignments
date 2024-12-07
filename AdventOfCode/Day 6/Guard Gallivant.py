filename = "input.txt"

with open(filename, "r") as file:
    map_input = file.readlines()

DIRECTIONS = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # UP  # RIGHT  # DOWN  # LEFT

SYMBOL_TO_DIRECTION = {"^": 0, ">": 1, "v": 2, "<": 3}


def find_guard_start(map_input):
    for row in range(len(map_input)):
        for column in range(len(map_input[0])):
            if map_input[row][column] in SYMBOL_TO_DIRECTION:
                return row, column, SYMBOL_TO_DIRECTION[map_input[row][column]]
    return None, None, None


def simulate_guard(map_input):
    rows = len(map_input)
    columns = len(map_input[0])
    visited = set()
    grid = [list(row) for row in map_input]  #
    row, column, direction = find_guard_start(grid)
    while 0 <= row < rows and 0 <= column < columns:
        visited.add((row, column))
        row_direction, column_direction = DIRECTIONS[direction]
        next_row, next_column = row + row_direction, column + column_direction
        if (
            0 <= next_row < rows
            and 0 <= next_column < columns
            and grid[next_row][next_column] == "#"
        ):
            direction = (direction + 1) % 4
        else:
            row, column = next_row, next_column
    return visited


print(f"number of visited positions: {len(simulate_guard(map_input))}")


### Part 2 ###
def simulate_guard_with_loop_check(map_input):
    rows = len(map_input)
    columns = len(map_input[0])
    grid = [list(row) for row in map_input]
    row, column, direction = find_guard_start(grid)

    visited_states = set()

    while 0 <= row < rows and 0 <= column < columns:
        state = (row, column, direction)
        if state in visited_states:
            return True
        visited_states.add(state)

        row_direction, column_direction = DIRECTIONS[direction]
        next_row, next_column = row + row_direction, column + column_direction

        if ( 0 <= next_row < rows
            and 0 <= next_column < columns
            and grid[next_row][next_column] == "#"):
            direction = (direction + 1) % 4
        else:
            row, column = next_row, next_column

    return False


def find_obstruction_positions(map_input):
    rows = len(map_input)
    columns = len(map_input[0])
    start_row, start_column, _ = find_guard_start(map_input)
    loop_positions = 0

    map_list = [list(row) for row in map_input]

    for row in range(rows):
        for column in range(columns):
            if map_list[row][column] == "." and (row, column) != (
                start_row,
                start_column,
            ):
                map_list[row][column] = "#"
                print(f"Checking position: {row}, {column}")
                if simulate_guard_with_loop_check(map_list):
                    loop_positions += 1
                map_list[row][column] = "."
    return loop_positions

print(f"Number of positions that cause a loop: {find_obstruction_positions(map_input)}")

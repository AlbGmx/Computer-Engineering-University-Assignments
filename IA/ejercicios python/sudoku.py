from tree import Tree
import numpy as np
from copy import deepcopy


state = np.array([['0' for _ in range(9)]for _ in range(9)])

def show(state):
    for row in range(9):
        for col in range(3):
            print(' '.join(state[row][col*3: (col+1)*3]), end=" | " if col<2 else '\n')
        if (row+1)%3 == 0:
            print('-'*21)
    
def init_state(state, n=9):
    for _ in range(n):
        pos = np.where(state.flatten() == '0')[0]
        pos = np.random.choice(pos)
        posx = pos//9
        posy = pos%9
        value = np.random.choice(list(get_possible_numbers(state, (posx, posy))))
        state[posx, posy] = value
    return state

def expand_node(node):
    flatten = node.value.flatten()
    pos = np.argwhere(flatten=='0')
    if len(pos)>0:
        pos = pos[0]

def get_possible_numbers(state, pos):
    all_values = set(map(str,range(1,10)))
    posx, posy = pos
    int_x, int_y = posx//3, posy//3
    row = set(state[posx,:])
    col = set(state[:,posy])
    internal_values = set(state[int_x*3:(int_x+1)*3, int_y*3:(int_y+1)*3].flatten())
    possible_values = all_values - row - col - internal_values
    return possible_values

def check_goal(state):
    return len(np.where(state.flatten()=='0')[0]) == 0

def expand_node(node):
    actual = deepcopy(node.value)
    pos = np.where(actual.flatten() == '0')[0]
    if len(pos)>0:
        pos = pos[0]
        posx = pos//9
        posy = pos%9
        for num in get_possible_numbers(actual, (posx, posy)):
            new_value = deepcopy(node.value)
            new_value[posx, posy] = num
            new_node = Tree(
                value = new_value,
                name = num
            )
            node.add_node(new_node)

state = init_state(state)
#state = ['0', '1', '2', '3', '4', ...]
print("PROBLEM")
show(state)
tree = Tree(state)
#result = tree.IDDFS(check_goal, expand_node, max_depth=10)
#result = tree.BFS(check_goal, expand_node)
result = tree.DFS(check_goal, expand_node)
#result = tree.A_star(check_goal, expand_node)

if result:
    print("\nSOLUTION")
    show(result.value)
from random import shuffle
from tree import Tree
from copy import deepcopy
import numpy as np
from scipy.spatial.distance import cityblock

ROW = 4
TILES = ROW**2

values = [str(v) for v in range(0,TILES)]
goal = deepcopy(values)

def show(state):
    for i, value in enumerate(state):
        tile = value if value!="0" else "[ ]"
        print(f'%4s'%(tile), end='\n' if  (i+1)%ROW==0 else ' ')
    print('')

def is_solvable(state):
    invertions = 0
    state = [int(i) for i in deepcopy(state)]
    for i in range(len(state)):
        for j in range(i+1,len(state)):
            if state[j]!=0 and state[i]!=0 and state[i]>state[j]:
                invertions+=1
    if ROW%2!=0:
        return invertions%2 == 0
    else:
        blank_row = state.index(0)//ROW
        if blank_row%2!=0 and  invertions%2!=0:
            return True
        elif blank_row%2==0 and  invertions%2==0:
            return True
    return False

def init_state(state):
    solvable = False
    while not solvable:
        shuffle(state)
        solvable = is_solvable(state)
    return state

def check_goal(state):
    for i in range(TILES):
        if state[i] != goal[i]:
            return False
    return True 

def perform_action(state, action):
    state = deepcopy(state)
    empty_pos = state.index('0')
    #print(empty_pos)
    row = empty_pos//ROW
    col = empty_pos%ROW
    #print(row, col)
    if action=='U':
        state[(row*ROW + col)] = state[( (row-1)*ROW + col)]
        state[( (row-1)*ROW + col)] = '0'
    elif action=='D':
        state[(row*ROW + col)] = state[( (row+1)*ROW + col)]
        state[( (row+1)*ROW + col)] = '0'
    elif action=='L':
        state[(row*ROW + col)] = state[( row*ROW + col-1)]
        state[( row*ROW + col-1)] = '0'
    elif action=='R':
        state[(row*ROW + col)] = state[( row*ROW + col+1)]
        state[( row*ROW + col+1)] = '0'
    return state

def expand_node(node):
    actions = set(['U', 'D', 'R', 'L'])
    empty_pos = node.value.index('0')
    row = empty_pos//ROW
    col = empty_pos%ROW
    if row==0:
        actions.remove('U')
    elif row==ROW-1:
        actions.remove('D')
    if col==0:
        actions.remove('L')
    elif col==ROW-1:
        actions.remove('R')
    for action in actions:
        new_node = Tree(
                    value = perform_action(node.value, action),
                    name = str(action)) 
        node.add_node(new_node)
    

state = init_state(values)
#state = ['0', '1', '2', '3', '4', .....]
print("PROBLEM")
show(state)
tree = Tree(state, name='START')
#result = tree.BFS(check_goal, expand_node)

def heuristic_function(state):
    actual = np.array([int(i) for i in state])
    goal = np.array(range(ROW**2))
    return cityblock(actual, goal)
    #return np.sum(actual != goal)

#result = tree.IDDFS(check_goal, expand_node, max_depth=10)
#result = tree.BFS(check_goal, expand_node)
#result = tree.DFS(check_goal, expand_node)
result = tree.A_star(check_goal, expand_node, h=heuristic_function)

if result:
    print("\nSOLUTION")
    show(result.value)
    print("Actions \n", tree.path)

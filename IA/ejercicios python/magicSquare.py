
from tree import Tree
from copy import deepcopy

def init_state():
    state = [[0 for i in range(3)] for _ in range(3)]
    return state

def show(state):
    for i in range(3):
        for j in range(3):
            end = ' | ' if j<2 else f' sum = {sum(state[i][:])}\n'
            print(state[i][j], end=end)

    print('sum')
    for j in range(3):
        end = ' | ' if j<2 else ''
        print(f'{sum(state[:][j])}', end=end)
    
    print('')


def set_values_in_order(state, values):
    state_ = deepcopy(state)
    open_positions = remaining_spaces(state_)
    for i,pos in enumerate(open_positions):
        posx, posy = pos
        if len(values)>i:
            state_[posx][posy] = values[i]
    return state_


def check_goal(state):
    for k in range(3):
        if sum(state[k][:]) != 15:
            return False
        acum_sum = 0
        for row in range(3):
            acum_sum += state[row][k]
        if acum_sum != 15:
            return False
    #harder
    # if (state[0][0] + state[1][1] + state[2][2]) != 15:
    #     return False

    #even more harder
    # if (state[0][2] + state[1][1] + state[2][0]) != 15:
    #    return False
    return True


def remaining_values(state):
    values_in_state = set(sum(state, []))
    return list(set(range(1,10)) - values_in_state)


def remaining_spaces(state):
    empty = []
    for i in range(3):
        for j in range(3):
            if  state[i][j] == 0:
                empty.append((i,j))
    return empty

def expand_node(tree):
    possible_values = remaining_values(tree.value)
    if len(possible_values) == 0:
        return None
    for value in possible_values:
        new_node = Tree( 
                    value = set_values_in_order(tree.value, [int(value)]),
                    name = str(value)) 
        tree.add_node(new_node)
    return tree

   
state = init_state() #blank state
state = [[3,0,0],
         [0,2,0],
         [0,0,0]]
print("PROBLEM")
show(state)
tree = Tree(state)
#result = tree.IDDFS(check_goal, expand_node, max_depth=10)
#result = tree.BFS(check_goal, expand_node)
#result = tree.DFS(check_goal, expand_node)
result = tree.A_star(check_goal, expand_node)
if result:
    print("\nSOLUTION")
    show(result.value)

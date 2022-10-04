from copy import deepcopy
from queue import Queue, LifoQueue, PriorityQueue
from cmath import inf
from functools import wraps
from time import time
import datetime


def timing(f):
    @wraps(f)
    def wrap(*args, **kw):
        ts = time()
        result = f(*args, **kw)
        te = time()
        print(f'Method:{f.__name__} elapsed time: {str(datetime.timedelta(seconds=int(te-ts)))}')
        return result
    return wrap


class Tree:

    @property
    def is_leaf(self):
        return len(self.children) == 0

    @property
    def is_root(self):
        return self.parent == None

    def __init__(self, value = None, name = None) -> None:
        self.value = deepcopy(value)
        self.children = []
        self.parent = None
        self.name: str = name
        self.branch: dict = {}
        self._traversal_references = []
        self.path = None
    
    def __getitem__(self, index):
        if isinstance(index, int):
            return self.children[index]
        elif index in self.branch:
            return self.children[self.branch[index]]
        else:
            raise KeyError()

    def add_node(self, tree):
        self.children.append(tree)
        tree.parent = self
        if tree.name is not None: 
            self.branch[tree.name] = len(self.children)-1
        return self

    #traversing methods
    @timing
    def preorder(self, node = None):
        if node is None:
            node = self
        if node.is_leaf:
            return
        print(node.value)
        for child in node.children:
            self.preorder(child)

    @timing
    def inorder(self, node = None, return_reference = False):
        if node is None:
            self._traversal_references = []
            node = self
        if node.is_leaf:
            return
        for child in node.children[:-1]:
            self.inorder(child, return_reference=return_reference)
        if return_reference == True:
            self._traversal_references.append(node)
        else:
            print(node.value)
        self.inorder(node.children[-1], return_reference=return_reference)

    @timing
    def postorder(self, node = None):
        if node is None:
            node = self
        if node.is_leaf:
            return
        for child in node.children:
            self.postorder(child)
        print(node.value)
    #end traversing methods

    #start searching methods
    @timing
    def BFS(self, goal_func, expand_node):
        queue = Queue()
        explored = set()
        explored.add(str(self.value))
        queue.put( (self, [self.name]) )
        while not queue.empty():
            node, path = queue.get()
            if goal_func(node.value):
                self.path = path
                return node
            expand_node(node)
            for child in node.children:
                if str(child.value) not in explored:
                    explored.add(str(child.value))
                    queue.put((child, path+[child.name]))

    @timing
    def DFS(self, goal_func, expand_node):
        stack = LifoQueue()
        stack.put( (self, [self.name]) )
        explored = set()
        while not stack.empty():
            node, path = stack.get()
            if goal_func(node.value):
                self.path = path
                return node
            if str(node.value) not in explored:
                explored.add(str(node.value))
                expand_node(node)
                for child in node.children:
                    stack.put( (child, path+[child.name]) )

    @timing
    def IDDFS(self, goal_func, expand_node, max_depth=5):
        root = self        
        for depth in range(max_depth):
            found, remaining =  self.DLS(root, depth, goal_func, expand_node)
            if found is not None:
                return found
            elif not remaining:
                return None

    def DLS(self, node, depth, goal_func, expand_node):
        node = deepcopy(node)
        if depth == 0:
            if goal_func(node.value):                
                return (node, True)
            else:
                return (None, True)   

        elif depth > 0:
            any_remaining = False
            expand_node(node)
            for child in node.children:
                found, remaining = self.DLS(child, depth-1, goal_func, expand_node)
                if found is not None:
                    return (found, True)   
                if remaining:
                    any_remaining = True 
            return (None, any_remaining)

    @timing
    def A_star(self, goal_func, expand_node, h=None, g=None):
        if g is None: 
            g = lambda x, y: 1
        if h is None: 
            h = lambda x: 0
        
        start = self
        dist = {}
        prev = {}
        f_score = {}
        dist[str(start.value)] = 0
        f_score[str(start.value)] = h(start.value)
        pq = PriorityQueue()
        open_set = set()
       
        pq.put((0, start, [start.name if start.name is not None else "ROOT"]))
        open_set.add(str(start.value))
        
        while not pq.empty():
            weight, node, path  = pq.get()
            open_set.remove(str(node.value))
            if goal_func(node.value):
                self.path = path
                return node
            expand_node(node)
            for child in node.children:
                g_score = dist[str(node.value)] + g(node, child)
                if str(child.value) not in dist:
                    dist[str(child.value)] = inf
                if g_score<dist[str(child.value)]:
                    prev[str(child.value)] = str(node.value)
                    dist[str(child.value)] = g_score
                    f_score[str(child.value)] = g_score + h(child.value)
                    if str(child.value) not in open_set:
                        pq.put((f_score[str(child.value)], child, path + [child.name]))
                        open_set.add(str(child.value))
        return None

    #end searching methods

    def show(self, max_level=-1, i=0):
        print(f'{"   "*(i-1)}{"└──" if i!= 0 else ""}{self.value}')
        #print(self.children)
        if max_level>0 and i == max_level:
           return
        for child in self.children:
            #print(child)
            child.show(i=i+1)
        if i==0:
            print('')

    def __lt__(self, other):
        return self.name<other.name

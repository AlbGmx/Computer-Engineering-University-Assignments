from cmath import inf
from copy import deepcopy
from queue import Queue, LifoQueue, PriorityQueue

class Node:
    def __init__(self, value = None, name = None) -> None:
        self.value = deepcopy(value)
        self.neighbors = []
        self.name: str = name
        self.branch: dict = {}


class Graph:

    def get_neighbors(self, node):
        if isinstance(node, Node):
            return list(self._arcs[node.name].items())
        elif isinstance(node, str):
            return list(self._arcs[node].items())

    def __init__(self, nodes = None, arcs = None, directed = False, start = None) -> None:
        self.nodes = nodes
        self.neighbors = []
        self.arcs = arcs
        self.branch: dict = {}
        self.directed = directed
        self._arcs = {}
        self.start = start
        self.path = None

        for name, node in self.nodes.items():
            node.name = name

        for arc in self.arcs:
            self._add_to_arcs_dict(arc)
            
    def _add_to_arcs_dict(self, arc):
        if len(arc) == 2:
                weight = 0
                start, end = arc
        elif len(arc) == 3:
            start, end, weight = arc
        else: 
            raise Exception('arc format error')

        if start not in self._arcs:
            self._arcs[start] = {}    

        self._arcs[start][end] =  weight

        if not self.directed:
            if end not in self._arcs:
                self._arcs[end] = {}  
            self._arcs[end][start] = weight


    def __getitem__(self, index):
        if isinstance(index, int):
            return self.neighbors[index]
        elif index in self.branch:
            return self.neighbors[self.branch[index]]
        else:
            raise KeyError()

    def add_node(self, node):
        if node.name not in self.nodes:
            self.nodes[node.name] = node
        return self
    
    def add_arc(self, arc):
        if isinstance(arc, tuple):
            if len(arc) == 2:
                weight = 0
                start, end = arc
                self.arcs.append( (start, end, weight) )
            elif len(arc) == 3:
                self.arcs.append(arc)
            else:
                raise TypeError()
            self._add_to_arcs_dict(arc)
        return self

    #start searching methods
    def BFS(self, goal_func, start=None):
        if start is None:
            start = self.start
        node = self.nodes[start]
        queue = Queue()
        explored = set()
        explored.add(str(node.value))
        queue.put( (node, [node.name]) )
        while not queue.empty():
            node, path = queue.get()
            if goal_func(node.value):
                self.path = path
                return node
            for node_name, weight in self.get_neighbors(node):
                neighbor = self.nodes[node_name]
                if str(neighbor.value) not in explored:
                    explored.add(str(neighbor.value))
                    queue.put( (neighbor, path+[neighbor.name]) )

    def DFS(self, goal_func, start=None):
        stack = LifoQueue()
        if start is None:
            start = self.start
        node = self.nodes[start]
        stack.put((node, [node.name]))
        explored = set()
        while not stack.empty():
            node, path = stack.get()
            if goal_func(node.value):
                self.path = path
                return node
            if str(node.value) not in explored:
                explored.add(str(node.value))
                for node_name, weight in self.get_neighbors(node):
                    neighbor = self.nodes[node_name]
                    stack.put((neighbor, path+[neighbor.name]))
    #end searching methods

    def dijkstra(self, start = None):
        if start is None:
            start = self.start
        dist = {}
        prev = {}
        dist[start] = 0
        pq = PriorityQueue()
        #node = self.nodes[start]
        for start_name, end_nodes in self._arcs.items():
            if start!=start_name:
                dist[start_name] = inf
                prev[start_name] = None
            pq.put((dist[start_name], start_name))
        
        while not pq.empty():
            u = pq.get()
            w, u = u
            for n,_ in self.get_neighbors(u):
                alt = dist[u] + self._arcs[u][n]
                if alt < dist[n]:
                    dist[n] = alt
                    prev[n] = u
                    pq.put((alt, n))
        return dist, prev



    def show(self):
        for start_node, end_nodes in self._arcs.items():
            print(f'{start_node} ---> {", ".join([ node_name for node_name, weight in list(end_nodes.items())])}')

nodes = {
    'a': Node(1),
    'b': Node(2),
    'g': Node(9)
}

arcs = [
    ('a', 'b', 1),
    ('b', 'g', 1)
]

g = Graph(nodes, arcs)
#g.add_node(Node(5, name='c')).add_arc(('c', 'a'))
g.BFS(lambda x: x==9, 'a')


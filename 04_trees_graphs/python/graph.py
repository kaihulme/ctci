class Node:
    """
    Graph node:
    - has value, neighbour list
    - add neighbour(s)
    - remove neighbour(s)
    - bfs, dfs
    """
    
    def __init__(self, x):
        self.val = x
        self.neighbours = []
        
    def add_neighbours(self, ns):
        self.neighbours.extend(ns)
        
    def add_neighbour(self, n):
        self.neighbours.append(n)

    def remove_neighbours(self, ns):
        for n in self.neighbours:
            self.remove_neighbour(n)
            
    def remove_neighbour(self, n):
        if n in self.neighbours:
            self.neighbours.remove(n)
            
            
            
class Graph:
    
    def __init__(self):
        self.nodes = []
    
    def create_from_dict(self, node_dict):
        for n in node_dict:
            node = Node(node_dict[n][0])
            self.nodes.append(node)
            neighbours = node_dict[n][1]
        
        
        
node_dict = {
    1: ('a', [2, 3]),
    2: ('b', [2, 3, 4]),
    3: ('c', [1, 2, 4]),
    4: ('d', [2, 3, 5, 6]),
    5: ('e', [4, 6]),
    6: ('f', [4, 5])
}
        
graph = Graph()
graph.create_from_dict(node_dict)    


    
        
        
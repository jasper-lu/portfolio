import collections

#For graphs with variable nodes/edges
#Example:
#   A: [B, C, D]
#   B: [C, A]
#   C: [B, D]
#   D: [A]

class Graph:
    def __init__(self):
        self.edges = {}
    def neighbors(self, id):
        return self.edges[id]

#Creates a grid with walls
class Grid:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.walls = []

    def in_bounds(self, coord):
        (x, y) = coord
        return x < self.width and x >= 0 and y < self.height and y >= 0

    def passable(self, coord):
        (x, y) = coord
        return (x, y) not in self.walls

    def neighbors(self, coord):
        (x, y) = coord
        neighbors = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y-1)]
        neighbors = filter(self.in_bounds, neighbors)
        neighbors = filter(self.passable, neighbors)
        return neighbors

class Queue:
    def __init__(self):
        self.elements = collections.deque()

    def empty(self):
        return len(self.elements) == 0

    def put(self, x):
        self.elements.append(x)

    def get(self):
        return self.elements.popleft()

#traces through the came_from dicts
def trace(path, end):
    trace = []
    
    while path[end]:
        trace.append(end)
        end = path[end]

    trace.append(end)

    return trace[::-1] #clarity

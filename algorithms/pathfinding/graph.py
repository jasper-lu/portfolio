import collections
import heapq

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

class WeightGrid(Grid):
    def __init__(self, width, height):
        super().__init__(width, height)
        self.weights = {}

    def cost(self, current, next):
        #default to 1
        return self.weights.get(coord, 1)

class Queue:
    def __init__(self):
        self.elements = collections.deque()

    def empty(self):
        return len(self.elements) == 0

    def put(self, x):
        self.elements.append(x)

    def get(self):
        return self.elements.popleft()

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def put(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def get(self):
        return heapq.heappop(self.elements)[1]

#traces through the came_from dicts
def trace(path, end):
    trace = []

    while path[end]:
        trace.append(end)
        end = path[end]

    trace.append(end)

    return trace[::-1] #clarity

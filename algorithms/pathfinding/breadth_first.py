from graph import Grid, Queue

def breadth_first_search(graph, start, end):
    frontier = Queue()
    frontier.put(start)
    came_from = {}
    came_from[start] = None

    while not frontier.empty():
        current = frontier.get()
        if current == end:
            print(came_from[current])
            break

        for x in graph.neighbors(current):
            frontier.put(x)
            came_from[x] = current

if __name__ == "__main__":
    graph = Grid(3,3)
    breadth_first_search(graph, (0,0), (3,3))

from graph import Grid, Queue, trace

def breadth_first_search(graph, start, end):
    frontier = Queue()
    frontier.put(start)
    came_from = {}
    came_from[start] = None

    while not frontier.empty():
        current = frontier.get()

        if current == end:
            break

        for x in graph.neighbors(current):
            if x not in came_from:
                frontier.put(x)
                came_from[x] = current

    return trace(came_from, end)

if __name__ == "__main__":
    graph = Grid(3,3)
    print(breadth_first_search(graph, (0,0), (1,2)))

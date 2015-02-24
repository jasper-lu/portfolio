from graph import Grid, Queue, trace

def astar_search(graph, start, end):
    frontier = Queue()
    frontier.put(start)
    came_from = {}
    came_from[start] = None

    return trace(came_from, end)

if __name__ == "__main__":
    graph = Grid(10,10)

    graph.walls = [(1,1),(2,2),(3,3),(4,4),(5,5),(6,6),(7,7),(8,8)]
    print(astar_search(graph, (0,0), (1,2)))

from graph import WeightGrid, PriorityQueue, trace

def djikstra_search(graph, start, end):
    frontier = PriorityQueue()
    frontier.put(start, 0)
    came_from = {}
    came_from[start] = None
    cost_so_far = {}
    cost_so_far[start] = 0

    while not frontier.empty():
        current = frontier.get()

        if current == end:
            break;

        for next in graph.neighbors(current):
            cost = cost_so_far[current] + graph.cost(current, next)
            #only if this node hasn't been checked yet, or this cost is less than the normal
            if next not in cost_so_far or cost < cost_so_far[next]:
                came_from[next] = current
                cost_so_far[next] = cost
                #priority queue automatically chooses the next best neighbor
                frontier.put(next, cost)

    return trace(came_from, end)

if __name__ == "__main__":
    graph = WeightGrid(10,10)

    graph.walls = [(1, 7), (1, 8), (2, 7), (2, 8), (3, 7), (3, 8), (4, 7), (4, 8)]
    print(djikstra_search(graph, (1, 4), (7, 8)))

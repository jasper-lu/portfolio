from graph import HWeightGrid, PriorityQueue, trace
#astar combines djikstra and greedy breadth-first search. I skipped greedy BFS since astar implements it already any way

def astar_search(graph, start, end):
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

                cost_so_far[next] = cost
                #nodes are sorted by hueristic + cost. tiebreaker added, favored to expand more to the end
                priority = graph.h(next, end) + cost
                #priority queue automatically chooses the next best neighbor
                frontier.put(next, priority)
                came_from[next] = current

    print(len(cost_so_far))
    return trace(came_from, end)

if __name__ == "__main__":
    graph = HWeightGrid(10,10)

    graph.walls = [(1, 7), (1, 8), (2, 7), (2, 8), (3, 7), (3, 8), (4, 7), (4, 8)]
    print(astar_search(graph, (1, 4), (7, 8)))

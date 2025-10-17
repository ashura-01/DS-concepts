from enum import Enum
from typing import List


class colors(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


def normalDFS(source: int, graph: list[List], color: List, result: List):
    color[source] = colors.GRAY
    result.append(source)

    for neighbors in graph[source]:
        if color[neighbors] == colors.WHITE:
            normalDFS(neighbors, graph, color, result)
    color[source] = colors.BLACK


path = []
parent = []


def cycleDFS(source: int, graph: List[List], color: List):
    color[source] = colors.GRAY

    for neighbor in graph[source]:
        if color[neighbor] == colors.WHITE:
            if cycleDFS(neighbor, graph, color):
                return True
        elif color[neighbor] == colors.GRAY:
            return True
    color[source] = colors.BLACK

    return False


def numberOfCycle(n, graph, color):
    count = 0
    for i in range(n):
        if color[i] == colors.WHITE:

            if cycleDFS(i, graph, color):
                count += 1
    return count


def cyclePath(source, graph: List[List], color: List, path: List, cycles):
    color[source] = colors.GRAY
    path.append(source)

    for neighbors in graph[source]:
        if color[neighbors] == colors.WHITE:
            cyclePath(neighbors, graph, color, path, cycles)

        elif color[neighbors] == colors.GRAY:
            cycle = []
            flag = False
            for nodes in path:
                if nodes == neighbors:
                    flag = True
                if flag:
                    cycle.append(nodes)
            cycle.append(neighbors)
            cycles.append(cycle)
    color[source] = colors.BLACK
    path.pop()

def printCycle(n,graph):
    color = [colors.WHITE]*n
    path=[]
    cycles=[]

    for i in range(n):
        if color[i]==colors.WHITE:
            cyclePath(i, graph, color, path, cycles)
    i=1
    for numbers in cycles:
        print("cycle ",i,":",numbers)
        i+=1

if __name__ == "__main__":
    n = 6
    graph = [[] for _ in range(n)]

    graph[0] = [1, 2]
    graph[3] = [5]
    graph[2] = [4]
    graph[1] = [3, 4]
    graph[4] = [2, 5]
    graph[5] = [3]

    color = [colors.WHITE] * n
    result = []

    normalDFS(0, graph, color, result)

    print(result)
    color = [colors.WHITE] * n
    print(f"the number of cycle {numberOfCycle(n,graph,color)}")

    printCycle(n,graph)

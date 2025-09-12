from enum import Enum


class Colors(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


def DFS(vertex, graph, color, parent, result):

    color[vertex] = Colors.GRAY
    result.append(vertex)

    for neighbor in graph[vertex]:

        if color[neighbor] == Colors.WHITE:  

            parent[neighbor] = vertex
            DFS(neighbor, graph, color, parent, result)

    color[vertex] = Colors.BLACK


if __name__ == "__main__":
    n = 6
    graph = [[] for _ in range(n)]
    graph[0] = [1, 2]
    graph[1] = [0, 3, 4]
    graph[2] = [0, 4]
    graph[3] = [1, 5]
    graph[4] = [1, 2, 5]
    graph[5] = [3, 4]

    color = [Colors.WHITE] * n
    parent = [-1] * n
    result = []

    DFS(0, graph, color, parent, result)

    print("DFS Order:", result)
    print("Parents:", parent)

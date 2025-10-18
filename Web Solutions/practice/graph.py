from collections import deque
from enum import Enum
from typing import List


"""normal BFS"""


def bfs(n, source, graph, result):

    level = [-1] * n
    que = deque()

    level[source] = 0
    que.append(source)
    result.append(source)

    while que:
        current = que.popleft()
        for neighbors in graph[current]:
            if level[neighbors] == -1:
                level[neighbors] = level[current] + 1
                que.append(neighbors)
                result.append(neighbors)


def BFS(n, source, graph, result):
    visited = [False] * n
    que = deque()

    visited[source] = True
    que.append(source)
    result.append(source)

    while que:
        current = que.popleft()
        for neighbor in graph[current]:
            if not visited[neighbor]:
                visited[neighbor] = True
                que.append(neighbor)
                result.append(neighbor)


"""bipartite"""


def isBipartite(n, graph):
    color = [-1] * n

    for i in range(n):
        if color[i] == -1:
            que = deque()
            color[i] = 0
            que.append(i)

        while que:
            current = que.popleft()
            for neighbors in graph[current]:
                if color[neighbors] == -1:
                    color[neighbors] = 1 - color[current]
                    que.append(neighbors)
                elif color[neighbors] == color[current]:
                    return False
    return True


"""topological sort"""


def toposort(n: int, graph):
    indegree = [0] * n

    for i in range(n):
        for neigh in graph[i]:
            indegree[neigh] += 1
    que = deque()

    for i in range(n):
        if indegree[i] == 0:
            que.append(i)
    result = []

    while que:
        node = que.popleft()
        result.append(node)

        for neigh in graph[node]:
            indegree[neigh] -= 1
            if indegree[neigh] == 0:
                que.append(neigh)
    return result


"""shortest path"""


def shortest_bfs(n, source, target, graph):
    visited = [False] * n
    parent = [-1] * n
    que = deque()

    visited[source] = True
    que.append(source)

    while que:
        current = que.popleft()
        if current == target:
            break
        for neighbors in graph[current]:
            if not visited[neighbors]:
                visited[neighbors] = True
                parent[neighbors] = current
                que.append(neighbors)

    # reconstruct path
    result = []
    if not visited[target]:
        return result  # no path found

    node = target
    while node != -1:
        result.append(node)
        node = parent[node]

    result.reverse()
    return result


class colors(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


"""normal dfs"""


def normalDFS(source: int, graph: list[List], color: List, result: List):
    color[source] = colors.GRAY
    result.append(source)

    for neighbors in graph[source]:
        if color[neighbors] == colors.WHITE:
            normalDFS(neighbors, graph, color, result)
    color[source] = colors.BLACK


"""number of cycle dfs"""


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


"""printing circular path"""


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


def printCycle(n, graph):
    color = [colors.WHITE] * n
    path = []
    cycles = []

    for i in range(n):
        if color[i] == colors.WHITE:
            cyclePath(i, graph, color, path, cycles)
    i = 1
    for numbers in cycles:
        print("cycle ", i, ":", numbers)
        i += 1


"""all path from source to destination"""


def allpath_dfs(source, target, graph, paths, storage, color):
    color[source] = colors.GRAY
    storage.append(source)

    if source == target:
        paths.append(storage[:])
    else:
        for neighbor in graph[source]:
            if color[neighbor] == colors.WHITE:
                allpath_dfs(neighbor, target, graph, paths, storage, color)

    storage.pop()
    color[source] = colors.WHITE


def allPathPrinting(n: int, source: int, target: int, graph: List[List[int]]):
    color = [colors.WHITE] * n
    paths = []
    storage = []

    allpath_dfs(source, target, graph, paths, storage, color)

    i = 1
    for path in paths:
        print("path", i, ":", path)
        i += 1


"""one path"""


def dfs_one_path(source, target, graph, color, path):
    color[source] = colors.GRAY
    path.append(source)

    if source == target:
        return True

    for neighbor in graph[source]:
        if color[neighbor] == colors.WHITE:
            if dfs_one_path(neighbor, target, graph, color, path):
                return True

    path.pop()
    color[source] = colors.WHITE
    return False


def any_path(n, source, target, graph):
    color = [colors.WHITE] * n
    path = []
    dfs_one_path(source, target, graph, color, path)
    return path


"""topo logical sort"""


def topoDFS(node: int, graph: List[List[int]], color: List[colors], stack: List[int]):
    color[node] = colors.GRAY

    for neighbor in graph[node]:
        if color[neighbor] == colors.WHITE:
            topoDFS(neighbor, graph, color, stack)

    color[node] = colors.BLACK
    stack.append(node)


def topologicalSort(n: int, graph: List[List[int]]) -> List[int]:
    color = [colors.WHITE] * n
    stack = []

    for i in range(n):
        if color[i] == colors.WHITE:
            topoDFS(i, graph, color, stack)

    stack.reverse()
    return stack


"""main function"""

if __name__ == "__main__":
    n = 6
    graph = [[] for _ in range(n)]

    graph[0] = [1, 2]
    graph[1] = [3, 4]
    graph[2] = [4]
    graph[3] = [5]
    graph[4] = [2, 5]
    graph[5] = [3]

    print("=== Normal DFS Traversal ===")
    color = [colors.WHITE] * n
    result = []
    normalDFS(0, graph, color, result)
    print("DFS Order:", result)

    print("\n=== Cycle Detection ===")
    color = [colors.WHITE] * n
    print(f"Number of Cycles: {numberOfCycle(n, graph, color)}")

    print("\n=== Printing All Cycles (if any) ===")
    printCycle(n, graph)

    print("\n=== All Paths from Source → Target ===")
    source, target = 0, 4
    allPathPrinting(n, source, target, graph)

    print("\n=== Topological Sort (DFS version) ===")
    if numberOfCycle(n, graph, [colors.WHITE] * n):
        print("Graph has a cycle — topological sort not possible.")
    else:
        print("Topological Order:", topologicalSort(n, graph))

    print("\n=== Topological Sort (Kahn’s Algorithm / BFS) ===")
    print("Topological Order:", toposort(n, graph))

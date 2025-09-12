from collections import deque

def bfs(graph, start, n):
    visited = [False] * n
    result = []
    level = [-1] * n

    que = deque()
    que.append(start)
    visited[start] = True
    result.append(start)
    level[start] = 0

    while que:
        current = que.popleft()

        for neighbor in graph[current]:
            if not visited[neighbor]:
                que.append(neighbor)
                visited[neighbor] = True
                result.append(neighbor)
                level[neighbor] = level[current] + 1

    return result, level


if __name__ == "__main__":
    n = 6
    graph = [[] for _ in range(n)]

    # Example undirected graph
    graph[0] = [1, 2]
    graph[1] = [0, 3, 4]
    graph[2] = [0, 4]
    graph[3] = [1, 5]
    graph[4] = [1, 2, 5]
    graph[5] = [3, 4]

    start = 0
    result, level = bfs(graph, start, n)

    print("BFS Order:", result)
    print("Levels:")
    for i in range(n):
        print(f"Node {i}: Level {level[i]}")

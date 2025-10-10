#
# @lc app=leetcode id=1971 lang=python3
#
# [1971] Find if Path Exists in Graph
#
'''BFS path related problem'''
# @lc code=start
from collections import deque
from typing import List


class Solution:
    def bfs(self, n:int, source:int, destination:int, graph):
        visited=[False]*n
        que = deque()

        visited[source]=True
        que.append(source)

        while que:

            current = que.pop()

            if current == destination:
                return True
            
            for neighbor in graph[current]:
                if not visited[neighbor]:
                    visited[neighbor]=True
                    que.append(neighbor)
        return False

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph: List[List[int]] = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        return self.bfs(n,source,destination,graph)
        
# @lc code=end


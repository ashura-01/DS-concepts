#
# @lc app=leetcode id=1971 lang=python3
#
# [1971] Find if Path Exists in Graph
#
from typing import List
from collections import deque
# @lc code=start
class Solution:
    def bfs(self,n: int, graph: List[List[int]], source: int, destination:int):

        visited=[False]*n
        que=deque()
        que.append(source)
        visited[source]=True

        while que:

            current = que.popleft()

            if current == destination:
                return True
            
            for elem in graph[current]:
                if not visited[elem]:
                    que.append(elem)
                    visited[elem]=True
        
        return False



    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph: List[List[int]] = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        return self.bfs(n,graph,source,destination)
        
# @lc code=end


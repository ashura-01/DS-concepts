#
# @lc app=leetcode id=886 lang=python3
#
# [886] Possible Bipartition
#

# @lc code=start
from collections import deque
from typing import List


class Solution:
    def isbipartite(self, n, graph):
        color = [-1]*(n+1)

        for i in range(n):
            if color[i]== -1:
                que = deque()
                color[i]=0
                que.append(i)

                while que:
                    vertex = que.popleft()
                    for neighbor in graph[vertex]:
                        if color[neighbor]==-1:
                            color[neighbor]=1-color[vertex]
                            que.append(neighbor)
                        elif color[vertex]==color[neighbor]:
                            return False
        return True
    
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        graph=[[] for _ in range(n+1)]

        for a,b in dislikes:
            graph[a].append(b)
            graph[b].append(a)

        return self.isbipartite(n,graph)
        
# @lc code=end


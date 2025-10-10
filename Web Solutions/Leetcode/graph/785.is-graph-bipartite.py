#
# @lc app=leetcode id=785 lang=python3
#
# [785] Is Graph Bipartite?
#

# @lc code=start
from collections import deque
from typing import List


class Solution:
    def bfspar(self,graph: List[List[int]]):
        n= len(graph)
        color =[-1]*n

        for i in range(n):
            if color[i]==-1:
                color[i]=0
                que = deque()
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
                    


    def isBipartite(self, graph: List[List[int]]) -> bool:
        return self.bfspar(graph)
        
        
# @lc code=end


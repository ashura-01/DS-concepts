#
# @lc app=leetcode id=547 lang=python3
#
# [547] Number of Provinces
#

# @lc code=start
from enum import Enum
from typing import List


class colors(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2

class Solution:
    
    def dfs(self,vertex, graph, color):
        color[vertex ]= colors.GRAY
        for neighbors in graph[vertex]:
            if color[neighbors]==colors.WHITE:
              self.dfs(neighbors, graph, color)
        color[vertex]=colors.BLACK

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n=len(isConnected)
        graph = [[] for _ in range(n)]

        for i in range(n):
            for j in range(n):
                if i != j and isConnected[i][j] == 1:
                    graph[i].append(j)

        color=[colors.WHITE]*n
        count =0
        for i in range(n):
            if color[i]==colors.WHITE:
                self.dfs(i,graph,color)
                count+=1

        return count



# @lc code=end

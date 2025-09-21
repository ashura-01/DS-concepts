#
# @lc app=leetcode id=733 lang=python3
#
# [733] Flood Fill
#

from typing import List


# @lc code=start
class Solution:
    def dfs(self, i: int, j: int, initColor: int, newColor: int, graph):

        n = len(graph)
        m = len(graph[0])

        if i < 0 or j < 0 or i >= n or j >= m:
            return
        if graph[i][j] != initColor:
            return
        graph[i][j] = newColor

        # up ward node
        self.dfs(i - 1, j, initColor, newColor, graph)

        self.dfs(i, j - 1, initColor, newColor, graph)
        self.dfs(i + 1, j, initColor, newColor, graph)
        self.dfs(i, j + 1, initColor, newColor, graph)

        

    def floodFill(self, graph: List[List[int]], sr: int, sc: int, newcolor: int ) -> List[List[int]]:
        initcolor = graph[sr][sc]

        if initcolor != newcolor:
            self.dfs(sr,sc,initcolor,newcolor,graph)
        return graph
# @lc code=end

#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#
from typing import List


# @lc code=start
class Solution:
    def dfs(self, i: int, j: int, visited, graph, n: int, m: int):

        if i < 0 or j < 0 or i >= n or j >= m or visited[i][j] or graph[i][j] != "1":
            return

        visited[i][j] = True

        # now to visit all the neighbors

        # top
        self.dfs(i - 1, j, visited, graph, n, m)
        # right
        self.dfs(i, j + 1, visited, graph, n, m)
        # bottom
        self.dfs(i + 1, j, visited, graph, n, m)
        # left
        self.dfs(i, j - 1, visited, graph, n, m)

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        n = len(grid)
        m = len(grid[0])

        visited = [[False] * m for _ in range(n)]

        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == "1" and not visited[i][j]:
                    self.dfs(i, j, visited, grid, n, m)
                    count += 1

        return count


# @lc code=end

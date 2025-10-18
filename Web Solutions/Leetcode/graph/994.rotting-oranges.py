#
# @lc app=leetcode id=994 lang=python3
#
# [994] Rotting Oranges
#

# @lc code=start
from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(-1,0), (1,0), (0,-1), (0,1)]
        que = deque()
        fresh_count = 0

        # Collect all rotten oranges and count fresh ones
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    que.append((i,j))
                elif grid[i][j] == 1:
                    fresh_count += 1

        if fresh_count == 0:
            return 0  # no fresh oranges

        time = 0
        # Multi-source BFS
        while que:
            for _ in range(len(que)):
                i, j = que.popleft()

                for dx, dy in directions:
                    newi, newj = i + dx, j + dy

                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == 1:
                        grid[newi][newj] = 2
                        que.append((newi,newj))
                        fresh_count -= 1

            time += 1  # one minute passed

        return time - 1 if fresh_count == 0 else -1


# @lc code=end

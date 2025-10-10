#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#
'''cycle detect problem'''

# @lc code=start
from typing import List
from enum import Enum


class Colors(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


class Solution:
    def dfs(self, vertex: int, graph: List[List[int]], color: List[Colors]) -> bool:

        color[vertex] = Colors.GRAY

        for neighbor in graph[vertex]:

            if color[neighbor] == Colors.WHITE:
                if self.dfs(neighbor, graph, color):
                    return True
                
            elif color[neighbor] == Colors.GRAY:
                return True
            
        color[vertex] = Colors.BLACK
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        graph = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            graph[b].append(a)

        color = [Colors.WHITE] * numCourses

        for i in range(numCourses):
            if color[i] == Colors.WHITE:
                if self.dfs(i, graph, color):
                    return False
        return True


# @lc code=end

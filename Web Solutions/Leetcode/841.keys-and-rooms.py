#
# @lc app=leetcode id=841 lang=python3
#
# [841] Keys and Rooms
#

# @lc code=start
from enum import Enum
from typing import List

class colors(Enum):
    WHITE =0
    GRAY =1
    BLACK=2

class Solution:
    def dfs(self, vertex,graph, visited):
        visited[vertex]=True

        for neighbor in graph[vertex]:
            if not visited[neighbor]:
                self.dfs(neighbor, graph, visited)

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited =[False]*n

        self.dfs(0,rooms, visited)

        for element in visited:
            if not element:
                return False
        return True
        
# @lc code=end


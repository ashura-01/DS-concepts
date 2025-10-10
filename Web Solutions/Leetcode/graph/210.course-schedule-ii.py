#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#
'''topological sorting problem'''
# @lc code=start
from collections import deque
from typing import List


class Solution:
    def toposort(self, n:int, graph:List[List[int]]) -> List[int]:
        indegree = [0]*n
        for i in range(n):
            for neighbor in graph[i]:
                indegree[neighbor]+=1
        que = deque()

        for i in range(n):
            if indegree[i] == 0:
                que.append(i)
        result=[]

        while que:

            vertex=que.pop()
            result.append(vertex)

            for neighbor in graph[vertex]:
                indegree[neighbor]-=1
                if indegree[neighbor]==0:
                    que.append(neighbor)
                    
        if len(result)!=n:
            return []
        else:
            return result
            
        
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        graph = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            graph[b].append(a)

        return self.toposort(numCourses,graph)

# @lc code=end


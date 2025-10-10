#
# @lc app=leetcode id=797 lang=python3
#
# [797] All Paths From Source to Target
#

from typing import List

# @lc code=start
class Solution:
    def dfs(self, vertex:int, target:int, graph:List[List[int]], result: List[List[int]], temp: List):

        temp.append(vertex)

        if vertex == target:
            result.append(temp[:])

        else:

            for neighbors in graph[vertex]:
                self.dfs(neighbors,target, graph, result, temp)

        temp.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        source = 0
        target = n-1

        result=[]
        temp = []

        self.dfs(source,target,graph, result, temp)
        return result
        
# @lc code=end


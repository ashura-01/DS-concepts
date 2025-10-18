#
# @lc app=leetcode id=997 lang=python3
#
# [997] Find the Town Judge
#

# @lc code=start
from typing import List


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        n = len(trust)

        indegree=[]
        outdegree=[]

        for a,b in trust:
            outdegree[a] +=1
            indegree[b]+=1

        for i in range(n):

            if indegree[i]==n-1 and outdegree[i]==0:
                return i
            else:
                return -1

        


        
# @lc code=end


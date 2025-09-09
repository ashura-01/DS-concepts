#
# @lc app=leetcode id=682 lang=python
#
# [682] Baseball Game
#

# @lc code=start
class stack:
    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        else:
            return None  

    def top(self):
        if not self.isEmpty():
            return self.stack[-1]
        else:
            return None

    def isEmpty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

class Solution(object):
    def calPoints(self, arr):
        """
        :type operations: List[str]
        :rtype: int
        """

        stk = stack()

        for element in arr:
            if element == "+":

               a = stk.top()
               stk.pop()
               b = stk.top()
               stk.push(a)           
               stk.push(a + b)

            elif element =="D":
                a=stk.top()
                stk.push(int(a*2))
            elif element =="C":
                stk.pop()
            else:
                stk.push(int(element))
        sum=0
        while not stk.isEmpty():
            sum+=stk.top()
            stk.pop()

        return sum
        
        
# @lc code=end


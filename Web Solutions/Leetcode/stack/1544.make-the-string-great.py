#
# @lc app=leetcode id=1544 lang=python3
#
# [1544] Make The String Great
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
    
class Solution:

    def caseSwap(self, char:str)->str:
        if char.isupper():
            return char.lower()
        else:
            return char.upper()
        
    def makeGood(self, s: str) -> str:
        stk= stack()

        for elem  in s:
            if not stk.isEmpty() and elem != stk.top() and elem.lower() == stk.top().lower():
                stk.pop()
            else:
                stk.push(elem)
        return "".join(stk.stack)

        
            
            

        
# @lc code=end


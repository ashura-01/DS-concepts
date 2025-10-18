#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
from typing import List

class stack:
    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        return None

    def top(self):
        if not self.isEmpty():
            return self.stack[-1]
        return None

    def isEmpty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)
    
class Solution:

    def evalRPN(self, postfix: List[str]) -> int:
        
        st = stack()

        for i in range(len(postfix)):

            if postfix[i].isdigit():
                st.push(int(postfix[i]))
            elif len(postfix[i])>1 and postfix[i][1].isdigit():
                st.push(int(postfix[i]))
            else:
                a = st.pop()
                b=st.pop()

                sum=0

                match postfix[i]:
                    case "+":
                        sum = b+a
                    case "-":
                        sum = b-a
                    case "*":
                        sum = b*a
                    case "/":
                        sum = int(b/a)
                st.push(sum)
        return st.top()
        
# @lc code=end


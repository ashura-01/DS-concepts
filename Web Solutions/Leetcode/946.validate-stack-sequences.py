#
# @lc app=leetcode id=946 lang=python3
#
# [946] Validate Stack Sequences
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
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stk = stack()

        n = len(pushed)
        i = 0

        for elements in pushed:
            stk.push(elements)

            while not stk.isEmpty() and stk.top() == popped[i]:
                stk.pop()
                i += 1

        return stk.isEmpty()


# @lc code=end

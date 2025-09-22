#
# @lc app=leetcode id=20 lang=python
#
# [20] Valid Parentheses
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
    def isValid(self, s):
        stk = stack()

        for char in s:
            # Single if for all opening brackets
            if char in ("(", "{", "["):
                stk.push(char)
            # Closing parentheses
            elif char == ")":
                if stk.isEmpty() or stk.top() != "(":
                    return False
                stk.pop()
            elif char == "}":
                if stk.isEmpty() or stk.top() != "{":
                    return False
                stk.pop()
            elif char == "]":
                if stk.isEmpty() or stk.top() != "[":
                    return False
                stk.pop()

        # Stack should be empty at the end for valid parentheses
        return stk.isEmpty()


# @lc code=end

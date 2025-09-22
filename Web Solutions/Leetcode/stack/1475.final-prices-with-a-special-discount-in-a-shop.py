#
# @lc app=leetcode id=1475 lang=python3
#
# [1475] Final Prices With a Special Discount in a Shop
#

# @lc code=start
# from typing import List

class Stack:
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
    def finalPrices(self, arr: List[int]) -> List[int]:
        n = len(arr)
        ans = []
        for i in range(n):
            discount = 0
            for j in range(i+1, n):
                if arr[j] <= arr[i]:   
                    discount = arr[j]
                    break
            ans.append(arr[i] - discount)
        return ans
                


        
# @lc code=end


#
# @lc app=leetcode id=530 lang=python3
#
# [530] Minimum Absolute Difference in BST
#

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


prev = None
minm = float("inf")


class Solution:

    def inorder(self, curr: Optional[TreeNode]):
        global prev, minm

        if curr is None:
            return
        self.inorder(curr.left)
        if prev is not None:
            minm = min(minm, abs(curr.val - prev))
        prev = curr.val
        self.inorder(curr.right)

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        global prev, minm
        prev = None
        minm = float("inf")
        self.inorder(root)
        return minm


# @lc code=end

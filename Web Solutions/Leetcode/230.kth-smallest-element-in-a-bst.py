#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
#

# @lc code=start
# Definition for a binary tree node.
# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorder(self, curr: Optional[TreeNode], k: list, stack: list):
        if curr is None or k[0] == 0:
            return

        self.inorder(curr.left, k, stack)

        k[0] -= 1
        if k[0] == 0:
            stack.append(curr.val)
            return

        self.inorder(curr.right, k, stack)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        self.inorder(root, [k], stack)
        return stack[-1]


# @lc code=end

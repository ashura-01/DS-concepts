#
# @lc app=leetcode id=653 lang=python3
#
# [653] Two Sum IV - Input is a BST
#

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorder(self, node: TreeNode, arr: List):
        if node is None:
            return
        self.inorder(node.left, arr)
        arr.append(node.val)
        self.inorder(node.right, arr)

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        arr = []
        self.inorder(root, arr)

        left = 0
        right = len(arr) - 1

        while left < right:
            sum = arr[left] + arr[right]
            if sum == k:
                return True
            elif sum < k:
                left += 1
            else:
                right -= 1
        return False


# @lc code=end

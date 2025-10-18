#
# @lc app=leetcode id=701 lang=python3
#
# [701] Insert into a Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

    def insert(self, node: TreeNode, value: int):
        if node is None:
            return TreeNode(value)
        if value < node.val:
            node.left = self.insert(node.left, value)
        else:
            node.right = self.insert(node.right, value)
        return node

    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        
        return self.insert(root, val)


# @lc code=end

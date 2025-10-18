#
# @lc app=leetcode id=700 lang=python3
#
# [700] Search in a Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        curr= root

        while curr is not None:
            if curr.val == val:
                return curr
            elif val<curr.val:
                curr=curr.left
            else:
                curr= curr.right
        return None
        
# @lc code=end


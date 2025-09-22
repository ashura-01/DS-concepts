#
# @lc app=leetcode id=141 lang=python
#
# [141] Linked List Cycle
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def hasCycle(self, root):
        """
        :type head: ListNode
        :rtype: bool
        """
        hare = root
        tortoise = root

        while hare is not None and hare.next is not None:
            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                return True
            
        return False
        
# @lc code=end


#
# @lc app=leetcode id=148 lang=python
#
# [148] Sort List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    
    def sort(self, root):
        i = root
        while i is not None:
            minm = i
            j = i.next
            while j is not None:
                if j.val < minm.val:
                    minm = j
                j = j.next
            i.val, minm.val = minm.val, i.val
            i = i.next
        return root

    def sortList(self, root):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        return self.sort(root)

        
# @lc code=end


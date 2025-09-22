#
# @lc app=leetcode id=83 lang=python
#
# [83] Remove Duplicates from Sorted List
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):



    def deleteDuplicates(self, root):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        curr = root

        while curr is not None:
            curr2 = curr
            
            while curr2.next is not None:
                if curr.val == curr2.next.val:
                    curr2.next = curr2.next.next
                else:
                    curr2 = curr2.next
            curr = curr.next
        return root


# @lc code=end

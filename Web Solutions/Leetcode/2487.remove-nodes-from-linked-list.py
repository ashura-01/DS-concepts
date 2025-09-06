#
# @lc app=leetcode id=2487 lang=python
#
# [2487] Remove Nodes From Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverse(self, root):
        prev = None
        curr=root
        aft=None

        while curr is not None:
            aft = curr.next
            curr.next=prev
            prev=curr
            curr=aft

        return prev
    
    def removeNodes(self, root):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        root = self.reverse(root)

        maxnode=-1
        prev = None
        curr= root

        while curr is not None:

            maxnode = max(maxnode,curr.val)

            if curr.val < maxnode:

                prev.next= curr.next
                curr=curr.next
                
            else:
                prev = curr
                curr=curr.next

        return self.reverse(root)
        
# @lc code=end


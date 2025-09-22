#
# @lc app=leetcode id=61 lang=python
#
# [61] Rotate List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):

    def rotate(self,root):
        curr= root
        prev = None

        while curr.next is not None:
            prev = curr
            curr=curr.next

        head = prev.next
        head.next= root
        root=head
        prev.next=None

        return root

    def length(self,root):
        curr= root
        count=0
        while curr is not None:
            count+=1
            curr= curr.next
        return count

        

    def rotateRight(self, root, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """

        size = self.length(root)

        if root is None or root.next is None or k == 0:
            return root
        
        if k==0:
            return root

        k = k%size

        while k:
            root=self.rotate(root)
            k-=1

        return root
        
# @lc code=end


#
# @lc app=leetcode id=160 lang=python
#
# [160] Intersection of Two Linked Lists
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def listlen(self, root):
        curr= root
        count = 0
        while curr is not None:
            count+=1
            curr= curr.next

        return count
            

    def getIntersectionNode(self, rootA, rootB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        lenA = self.listlen(rootA)
        lenB=self.listlen(rootB)

        tempA= rootA
        tempB=rootB

        diff = abs(lenA-lenB)

        if lenA>lenB:
            while diff != 0:
                tempA = tempA.next
                diff-=1
        else:
            while diff != 0:
                tempB = tempB.next
                diff-=1

        while tempA != tempB:
            tempA = tempA.next
            tempB = tempB.next

            if tempA is None or tempB is None:
                return None
        return tempA
            


            


        
# @lc code=end


#
# @lc app=leetcode id=1598 lang=python
#
# [1598] Crawler Log Folder
#

# @lc code=start
class Solution(object):
    def minOperations(self, logs):
        """
        :type logs: List[str]
        :rtype: int
        """
        stack = []
        for log in logs:
            if log == "../":
                if stack:  # only pop if not empty
                    stack.pop()
            elif log == "./":
                continue
            else:
                stack.append(log)
        return len(stack)


        
# @lc code=end


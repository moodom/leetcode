#  Source : https://leetcode.com/problems/valid-parentheses/
#  Author : FangY
#  Date   : 2019-12-2
# *******************************************************************************
# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Note that an empty string is also considered valid.

# Example 1:

# Input: "()"
# Output: true
# Example 2:

# Input: "()[]{}"
# Output: true
# Example 3:

# Input: "(]"
# Output: false
# Example 4:

# Input: "([)]"
# Output: false
# Example 5:

# Input: "{[]}"
# Output: true
# *******************************************************************************
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack=[]
        for i in s:
            if i=='(':
                stack.append(')')
            elif i=='{':
                stack.append('}')
            elif i=='[':
                stack.append(']')
            elif len(stack)==0 or stack.pop(-1)!=i:
                return False
        return len(stack)==0
#  Source : https://leetcode.com/problems/generate-parentheses/
#  Author : FangY
#  Date   : 2019-12-4
# *******************************************************************************
# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

# For example, given n = 3, a solution set is:

# [
#   "((()))",
#   "(()())",
#   "(())()",
#   "()(())",
#   "()()()"
# ]
# *******************************************************************************
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res=[]
        def recallParenthesis(cur='',left=0,right=0):
            if len(cur)==2*n:
                res.append(cur)
            if left<n:
                recallParenthesis(cur+'(',left+1,right)
            if right<left:
                recallParenthesis(cur+')',left,right+1)
        recallParenthesis()
        return res
#  Source : https://leetcode.com/problems/palindromic-substrings/
#  Author : FangY
#  Date   : 2019-12-4
# *******************************************************************************
# Given a string, your task is to count how many palindromic substrings in this string.

# The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

# Example 1:

# Input: "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
 

# Example 2:

# Input: "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# *******************************************************************************
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = '#' + '#'.join(s) + '#'
        p=[0]*len(s)
        mx=0
        id=0
        for i in range(1,len(s)-1):
            if(mx>i):
                p[i]=min(p[2*id-i],mx-i)
            else:
                p[i]=1
            while(i-p[i]>=0 and i+p[i]<len(s) and s[i+p[i]]==s[i-p[i]]):
                p[i]+=1
            if(i+p[i]>mx):
                id=i
                mx=i+p[i]
        p=[ i//2 for i in p]
        return sum(p)
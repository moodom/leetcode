#  Source : https://leetcode.com/problems/group-anagrams/
#  Author : FangY
#  Date   : 2019-12-3
# *******************************************************************************
# Given an array of strings, group anagrams together.

# Example:

# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
#   ["ate","eat","tea"],
#   ["nat","tan"],
#   ["bat"]
# ]
# Note:

# All inputs will be in lowercase.
# The order of your output does not matter.
# *******************************************************************************
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        sort_strs=["".join((lambda x:(x.sort(),x)[1])(list(s))) for s in strs] #排序
        set_strs=set(sort_strs)
        strs_dict={item:[] for item in set_strs}
        for i in range(len(sort_strs)):
            strs_dict[sort_strs[i]].append(strs[i])
        return  strs_dict.values()

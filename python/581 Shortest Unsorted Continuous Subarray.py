#  Source : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#  Author : FangY
#  Date   : 2019-12-4
# *******************************************************************************
# Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

# You need to find the shortest such subarray and output its length.

# Example 1:
# Input: [2, 6, 4, 8, 10, 9, 15]
# Output: 5
# Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
# Note:
# Then length of the input array is in range [1, 10,000].
# The input array may contain duplicates, so ascending order here means <=.
# *******************************************************************************
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        sort_nums=sorted(nums)
        if nums==sort_nums:
            return 0
        length=len(nums)
        index1=index2=-1
        for i in range(length):
            if(nums[i]!=sort_nums[i] and index1==-1):
                index1=i
            elif(nums[i]!=sort_nums[i] and index1!=-1):
                index2=i
        return index2-index1+1
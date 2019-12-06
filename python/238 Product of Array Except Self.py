#  Source : https://leetcode.com/problems/product-of-array-except-self/
#  Author : FangY
#  Date   : 2019-12-5
# *******************************************************************************
# Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

# Example:

# Input:  [1,2,3,4]
# Output: [24,12,8,6]
# Note: Please solve it without division and in O(n).

# Follow up:
# Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
# *******************************************************************************
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        N = len(nums)
        ans = [1] * N
        
        for i in xrange(1, N):
            ans[i] = ans[i - 1] * nums[i - 1]
        
        mul = 1
        for i in xrange(N - 1, -1, -1):
            ans[i] *= mul
            mul *= nums[i]            
        
        return ans
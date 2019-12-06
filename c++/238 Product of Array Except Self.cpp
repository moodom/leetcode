// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : FangY
// Date   : 2019-12-5
/*******************************************************************************
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*******************************************************************************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N;
        N=nums.size();
        vector<int> ans(N,1);
        for(int i=1;i<nums.size();i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int mul=1;
        for(int i=nums.size()-1;i>-1;i--){
            ans[i]*=mul;
            mul*=nums[i];
        }
        return ans;
    }
};
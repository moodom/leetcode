// Source : https://leetcode.com/problems/combination-sum/
// Author : FangY
// Date   : 2019-12-6
/*******************************************************************************
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*******************************************************************************/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target,out);
        return ans;
    }
    void dfs(vector<int>& candidates,int remain,vector<int>& out){
        if(remain==0){
            ans.push_back(out); 
            return;
        } 
        for(auto candidate:candidates){
            if(candidate>remain) break;
            if(out.empty() || candidate>=out.back()){
                out.push_back(candidate);
                dfs(candidates,remain-candidate,out);
                out.pop_back();
            }
        }
        
    }
};
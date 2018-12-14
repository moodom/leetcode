// Source : https://leetcode.com/problems/top-k-frequent-elements/
// Author : FangY
// Date   : 2018-12-14
/*******************************************************************************
*Given a non-empty array of integers, return the k most frequent elements.
*
*Example 1:
*
*Input: nums = [1,1,1,2,2,3], k = 2
*Output: [1,2]
*Example 2:
*
*Input: nums = [1], k = 1
*Output: [1]
*Note:
*
*You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
*Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len=nums.size();
        vector<int> topnums;
        pair<int,int> temp;
        unordered_map<int,int> numFrequent;
        for(const auto& num:nums) numFrequent[num]++;
        vector<pair<int, int>> pairFrequent;
        for(auto m:numFrequent){
            temp.first=m.first;
            temp.second=m.second;
            pairFrequent.push_back(temp);
        }
        sort(pairFrequent.begin(),pairFrequent.end(),mycmp);
        for(int i=0;i<k;i++){
            topnums.push_back(pairFrequent[i].first);
        }
        return topnums;
    }
    struct cmp{
        bool operator()(const pair<int,int>& p1,const pair<int,int>& p2){
            if (p1.second>p2.second) return true;
            else return false;
        }
    }mycmp;
};
int main()
{
    vector<int> nums={1,1,1,2,2,3};
    vector<int> topnums;
    int k=2;
    Solution a;
    topnums=a.topKFrequent(nums,k);
    for(auto num:topnums) cout<<num<<endl;

}

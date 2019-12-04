// Source : https://leetcode.com/problems/group-anagrams/
// Author : FangY
// Date   : 2019-12-3
/*******************************************************************************
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*******************************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.empty()) return ret;
        unordered_map<string, vector<string>> hash;
        for(auto str:strs){
            string temp=str;
            sort(temp.begin(),temp.end());
            hash[temp].push_back(str);
        }
        for(auto item:hash){
            vector<string> sol(item.second.begin(),item.second.end());
            ret.push_back(sol);
        }
        return ret;
    }
};
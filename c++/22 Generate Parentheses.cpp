// Source : https://leetcode.com/problems/generate-parentheses/
// Author : FangY
// Date   : 2019-12-4
/*******************************************************************************
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*******************************************************************************/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        recallParenthesis(n,"",0,0,res);
        return res;
    }
    void recallParenthesis(int n, string cur, int left, int right,vector<string> &res) {
            if(cur.size()==2*n) res.push_back(cur);
            if(left<n) recallParenthesis(n,cur+'(',left+1,right,res);
            if(right<left) recallParenthesis(n, cur+')',left,right+1,res);
    }
};
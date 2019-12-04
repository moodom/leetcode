// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : FangY
// Date   : 2019-12-3
/*******************************************************************************
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*******************************************************************************/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits=="") return ret;
        vector<string> ret_pre;
        ret_pre.push_back("");
        vector<string> num(10);
        num[2]="abc";
        num[3]="def";
        num[4]="ghi";
        num[5]="jkl";
        num[6]="mno";
        num[7]="qprs";
        num[8]="tuv";
        num[9]="wxyz";
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<ret_pre.size();j++){
                for(int k=0;k<num[digits[i]-'0'].size();k++){
                    ret.push_back(ret_pre[j]+num[digits[i]-'0'][k]);
                }
            }
            ret_pre.swap(ret);
            ret.clear();
        }
        return ret_pre;
    }
};
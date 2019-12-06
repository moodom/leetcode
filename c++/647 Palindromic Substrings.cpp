// Source : https://leetcode.com/problems/palindromic-substrings/
// Author : FangY
// Date   : 2019-12-4
/***************************************************************************************
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

******************************************************************************************/
class Solution {
public:
    int countSubstrings(string s) {
        string t="#";
        for(auto i:s) t=t+i+'#';
        
        int id=0;
        int mx=0;
        int res=0;
        int p[t.size()];
        for(int i=1;i<t.size();i++){
            if(mx>i) p[i]=min(p[2*id-i],mx-i);
            else p[i]=1;
        
            while(i-p[i]>=0 && i+p[i]<t.size() && t[i-p[i]]==t[i+p[i]]){
                p[i]++;
            }
            res+=p[i]/2;
        }
    return res;
    }
};

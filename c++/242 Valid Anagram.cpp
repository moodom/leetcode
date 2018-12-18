// Source : https://leetcode.com/problems/valid-anagram/
// Author : FangY
// Date   : 2018-12-18
/*******************************************************************************
*Given two strings s and t , write a function to determine if t is an anagram of s.
*
*Example 1:
*
*Input: s = "anagram", t = "nagaram"
*Output: true
*Example 2:
*
*Input: s = "rat", t = "car"
*Output: false
*Note:
*You may assume the string contains only lowercase alphabets.
*
*Follow up:
*What if the inputs contain unicode characters? How would you adapt your solution to such case?
*******************************************************************************/
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_count;
        unordered_map<char,int> t_count;
        for(char i:s) s_count[i]++;
        for(char i:t) t_count[i]++;
        if(s_count==t_count) return true;
        else return false;

    }
};
int main()
{
    string s="rat";
    string t="cat";
    Solution a;
    bool result;
    result=a.isAnagram(s,t);
    cout<<result<<endl;

}


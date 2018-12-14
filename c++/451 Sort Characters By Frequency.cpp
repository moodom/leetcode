// Source : https://leetcode.com/problems/sort-characters-by-frequency/
// Author : FangY
// Date   : 2018-12-14
/*******************************************************************************
*Given a string, sort it in decreasing order based on the frequency of characters.
*
*Example 1:
*
*Input:
*"tree"
*
*Output:
*"eert"
*
*Explanation:
*'e' appears twice while 'r' and 't' both appear once.
*So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*Example 2:
*
*Input:
*"cccaaa"
*
*Output:
*"cccaaa"
*
*Explanation:
*Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
*Note that "cacaca" is incorrect, as the same characters must be together.
*Example 3:
*
*Input:
*"Aabb"
*
*Output:
*"bbAa"
*
*Explanation:
*"bbaA" is also a valid answer, but "Aabb" is incorrect.
*Note that 'A' and 'a' are treated as two different characters.
*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int len=s.size();
        unordered_map<char,int> mapCharacters;
        vector<string> vec(len+1,"");
        for(auto ch: s) mapCharacters[ch]++;
        for(auto val:mapCharacters) vec[val.second].append(val.second,val.first);
        string ans;
        for(int i=len;i>0;i--){
            ans+=vec[i];
        }
    return ans;
    }
    struct cmp{
        bool operator()(const pair<char,int>& p1,const pair<char,int>& p2){
            if(p1.second>p2.second) return true;
            else return false;
        }
    }mycmp;
    string frequencySort2(string s) {
        vector<pair<char, int>> count{100, make_pair(' ', 0)};
        for(const auto& ch:s){
            count[ch - ' '].first = ch;
            count[ch - ' '].second++;
        }
        sort(count.begin(), count.end(), mycmp);
        string rtn = "";
        for(const auto& p:count){
            for(int i = 0; i<p.second; ++i){
                rtn += p.first;
            }
        }
        return rtn;
    }
};
int main()
{
    string s,b;
    s={'t','r','e','e'};
    Solution a;
    b=a.frequencySort2(s);
    cout<<b<<endl;

}

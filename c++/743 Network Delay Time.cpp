// Source : https://leetcode.com/problems/network-delay-time/
// Author : FangY
// Date   : 2019-1-23
/*******************************************************************************
*There are N network nodes, labelled 1 to N.
*
*Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
*
*Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
*
*Note:
*N will be in the range [1, 100].
*K will be in the range [1, N].
*The length of times will be in the range [1, 6000].
*All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*******************************************************************************/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> v(N+1,INT_MAX);
        v[K]=0;
        int loop=1;
        while(loop--){
            for(int i=0;i<times.size();i++){
                if(v[times[i][0]]!=INT_MAX){
                    int t=v[times[i][1]];
                    v[times[i][1]]=min(v[times[i][0]]+times[i][2],t);
                    if(t!=v[times[i][1]])loop=1;
                }
            }
        }
        int maxnum=0;
        for(int j=1;j<=N;j++){
            if(v[j]==INT_MAX)return -1;
            maxnum=max(maxnum,v[j]);
        }
        return maxnum;
    }
};

int main()
{
    vector<vector<int>> weight={{2,1,1},{2,3,1},{3,4,1}};
    Solution a;
    int b;
    b=a.networkDelayTime(weight,4,2);
    cout<<b;


}


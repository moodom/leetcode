// Source : https://leetcode.com/problems/sort-colors/
// Author : FangY
// Date   :
/*******************************************************************************

*******************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& A) {
        int i = -1;
        int j = -1;
        int k = -1;
        int n=A.size();
        for(int p = 0; p < n; p ++)
        {
            if(A[p] == 0)
            {
                A[++k] = 2;
                A[++j] = 1;
                A[++i] = 0;
            }
            else if(A[p] == 1)
            {
                A[++k] = 2;
                A[++j] = 1;
            }
            else
                A[++k] = 2;
        }

    }
    void sortColors2(vector<int>& A){
        vector<int> B{A};
        int c[3]={0,0,0};
        int index;
        for(auto a:A) c[a]++;
        c[1]=c[0]+c[1];
        c[2]=c[1]+c[2];
        for(int i=A.size()-1;i>=0;i--){
            index=B[i];
            A[c[index]-1]=index;
            c[index]--;
        }
    }
};
int main()
{
    vector<int> num={2,0,2};
    Solution a;
    a.sortColors2(num);
    for(auto i:num) cout<<i<<endl;
}

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
};
int main()
{
    vector<int> num={2,0,2,1,1,0};
    Solution a;
    a.sortColors(num);
    for(auto i:num) cout<<i<<endl;
}

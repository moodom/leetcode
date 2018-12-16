// Author : FangY
// Date   : 2018-12-16
#include<iostream>
using namespace std;

void quickSort(int s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j]>= x)
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x)
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}
int main()
{
    int a;
    int A[11]={-5,-1,2,3,6,5,7,-7,9,3,2};
    quickSort(A,0,10);
    for(auto i:A) cout<<i<<endl;

}

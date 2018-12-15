// Source : https://leetcode.com/problems/top-k-frequent-elements/
// Author : FangY
// Date   : 2018-12-14
/*******************************************************************************
*Given a non-empty array of integers, return the k most frequent elements.
*
*Example 1:
*
*Input: nums = [1,1,1,2,2,3], k = 2
*Output: [1,2]
*Example 2:
*
*Input: nums = [1], k = 1
*Output: [1]
*Note:
*
*You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
*Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
#define PARENT(i) ((i-1)/2)
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len=nums.size();
        vector<int> topnums;
        pair<int,int> temp;
        unordered_map<int,int> numFrequent;
        for(const auto& num:nums) numFrequent[num]++;
        vector<pair<int, int>> pairFrequent;
        for(auto m:numFrequent){
            temp.first=m.first;
            temp.second=m.second;
            pairFrequent.push_back(temp);
        }
        sort(pairFrequent.begin(),pairFrequent.end(),mycmp);
        for(int i=0;i<k;i++){
            topnums.push_back(pairFrequent[i].first);
        }
        return topnums;
    }
    struct cmp{
        bool operator()(const pair<int,int>& p1,const pair<int,int>& p2){
            if (p1.second>p2.second) return true;
            else return false;
        }
    }mycmp;
};
class PriorityQueue {
public:
    void maxHeapify(vector<pair<int,int>>& A, int i){
        int largest=i;
        int l,r;
        int N=A.size();
        l=LEFT(i);
        r=RIGHT(i);
       if(l<N && A[largest].second<A[l].second){
          largest=l;
        }
        if(r<N && A[largest].second<A[r].second){
            largest=r;
        }
        if(largest!=i){
            swap(A[i],A[largest]);
            maxHeapify(A,largest);
        }
    }

    void heapInsert(vector<pair<int,int>>& A,pair<int,int> key){
        A.push_back(key);
        int i=A.size()-1;
        while(i>0 && A[PARENT(i)].second<A[i].second){
            swap(A[i],A[PARENT(i)]);
            i=PARENT(i);
        }

    }
    pair<int,int> extractMax(vector<pair<int,int>>& A){
        pair<int,int> maxKey;
        maxKey=A.back();
        A.erase(A.end());
        return maxKey;
    }
    vector<int> topKFrequent2(vector<int>& nums, int k) {

        vector<int> topnums;
        pair<int,int> temp;
        unordered_map<int,int> numFrequent;
        for(const auto& num:nums) numFrequent[num]++;
        vector<pair<int, int>> pairFrequent;
        for(auto m:numFrequent){
            temp.first=m.first;
            temp.second=m.second;
            heapInsert(pairFrequent,temp);
        }
        int len=pairFrequent.size()-1;
        for(int i=0;i<k;i++){
            swap(pairFrequent[0],pairFrequent[len-i]);
            topnums.push_back(extractMax(pairFrequent).first);
            maxHeapify(pairFrequent,0);
        }
        return topnums;
    }

};



int main()
{
    vector<int> nums={1};
    vector<int> topnums;
    int k=1;
    PriorityQueue a;
    topnums=a.topKFrequent2(nums,k);
    for(auto num:topnums) cout<<num<<endl;

}

// Author : FangY
// Date   : 2018-12-12
#include<iostream>
using namespace std;
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)
#define NUM 13
void maxHeapify(int A[], int i,int N){
    int largest=i;
    int l,r;
    l=LEFT(i);
    r=RIGHT(i);
   if(l<N && A[largest]<A[l]){
      largest=l;
    }
    if(r<N && A[largest]<A[r]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        maxHeapify(A,largest,N);
    }
}
void heapSort(int A[],int N){
    //build max-heap
    for(int i=N/2;i>=0;i--){
        maxHeapify(A,i,N);
    }
    for(int i=N-1;i>=0;i--){
        swap(A[0],A[i]);
        maxHeapify(A,0,i);

    }
}
int main()
{
    int A[NUM]={4,5,3,5,2,1,8,5,4,3,4,5,6};
    heapSort(A,NUM);
    for(int i=0;i<NUM;i++){
        cout<<A[i]<<endl;
    }
}


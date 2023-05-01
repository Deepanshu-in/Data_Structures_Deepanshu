#include<bits/stdc++.h>
using namespace std;


int insertAtPos(int *arr,int n,int pos,int ele){
    int idx=pos-1;
    n=n+1;
    for(int i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    arr[idx]=ele;
    return n+1;
}

void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5]={1,2,3,5,6};
    insertAtPos(arr,5,4,4);
    insertAtPos(arr,5,3,9);
    printArr(arr,7);
    return 0;
}
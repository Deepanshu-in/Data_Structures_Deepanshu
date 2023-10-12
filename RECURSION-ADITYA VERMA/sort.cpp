#include<bits/stdc++.h>
using namespace std; 

int sorts(int arr[],int n){
    if(n==1){
        return n;
    }
    if(arr[n-1]<arr[n-2]) {
        swap(arr[n-1],arr[n-2]);
        return sorts(arr,n-1);
    }
    else{
        return sorts(arr,n-1);
    }
}
int main()
{
    int arr[5]={5,2,6,23,3};
    sorts(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
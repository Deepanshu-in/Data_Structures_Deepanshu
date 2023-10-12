#include<bits/stdc++.h>
using namespace std;

int cntDistinct(int arr[],int n){
    // unordered_set<int> s;
    // for(int i=0;i<n;i++){
    //     s.insert(arr[i]);
    // }
    //or we can write
    unordered_set<int> s(arr,arr+n);
    return s.size();
}
int main()
{
    int arr[7]={15,12,13,12,13,13,18};
    cout<<cntDistinct(arr,7);
    return 0;
}
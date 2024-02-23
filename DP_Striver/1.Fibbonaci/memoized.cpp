#include<bits/stdc++.h>
using namespace std;


int solve(int n,vector<int> & arr)
{
    if(n<=1)
        return n;
    if(arr[n]!=-1)
        return arr[n];
    
    arr[n]=solve(n-1,arr)+solve(n-2,arr);
    return arr[n];
}
int main()
{ 
    int n;
    cin>>n;
    vector<int> arr(n+1,-1);
    cout<<solve(n,arr);
    return 0;
}
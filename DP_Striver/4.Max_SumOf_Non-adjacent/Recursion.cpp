//problem Link :https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int ind)
{
    int pick=0,notPick=0;
    if(ind==0)
        return arr[ind];
    if(ind<0)
        return 0;
    
    pick=arr[ind]+solve(arr,ind-2);
    notPick=0+solve(arr,ind-1);
    return max(pick,notPick);
}
int main()
{
    int arr[9]={1,2,3,1,3,5,8,1,9};
    cout<<solve(arr,8);
    return 0;
}

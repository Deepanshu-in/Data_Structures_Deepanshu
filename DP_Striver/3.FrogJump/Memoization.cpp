//problem Link :https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, int heights[],vector<int> & dp)
{
    int left,right=INT_MAX;
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    left=frogJump(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    if(n>1)
        right=frogJump(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    vector<int> dp(n+1,-1);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<frogJump(n-1,arr,dp);
    return 0;
}
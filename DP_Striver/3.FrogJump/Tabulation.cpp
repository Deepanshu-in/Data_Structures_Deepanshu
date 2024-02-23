//problem Link :https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, int heights[],vector<int> & dp)
{
    int left,right=INT_MAX;
    
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        int left=dp[n-1]+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=dp[n-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    vector<int> dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<frogJump(n-1,arr,dp);
    return 0;
}
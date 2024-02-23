#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &dp)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n,0);
    cout<<solve(n,dp);
    return 0;
}
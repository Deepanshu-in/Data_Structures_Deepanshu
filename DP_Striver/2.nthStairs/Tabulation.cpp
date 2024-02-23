//problem link : https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//when to apply recursion:
//where the problem is given to count all possible ways or find the best possible way

// Points to remember:
// Step1. Identify a DP Problem.
// Step2. To solve the problem after identification.
//    1. Try to represent the given problem in terms of index.
//    2. Do all possible operations on that index according to the problem statement.
//    3. To count all possible ways - sum of all stuff.
//         To find minimum/maximum - Take Minimum/maximum of all stuff.


#include<bits/stdc++.h>
using namespace std;


int solve(int n,vector<int> &dp)
{
    dp[0]=1;
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
    vector<int> dp(n);
    cout<<solve(n,dp);
    return 0;
}
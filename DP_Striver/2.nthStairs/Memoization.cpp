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
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<solve(n,dp);
    return 0;
}
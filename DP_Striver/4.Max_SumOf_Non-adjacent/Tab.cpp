//problem Link :https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[9]={1,2,3,1,3,5,8,1,9};
    int dp[9]={0};
    int take=0,notTake=0;
    dp[0]=arr[0];
    for(int i=1;i<9;i++)
    {
        
        take=arr[i];
        if(i>1)
            take+=dp[i-2];
        notTake=0+dp[i-1];
        dp[i]=max(take,notTake);
    }
    cout<< dp[8];
}

//problem link : https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;


int solve(int n)
{
    int prev=1;
    int prev2=1;
    for(int i=2;i<=n;i++)
    {
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
//problem Link :https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, int heights[])
{
    int prev=0,prev2=0;
    for(int i=1;i<=n;i++)
    {
        int left=prev+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=prev2+abs(heights[i]-heights[i-2]);
        int curr=min(left,right);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<frogJump(n-1,arr);
    return 0;
}
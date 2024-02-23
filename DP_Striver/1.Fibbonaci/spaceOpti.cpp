#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int prev2=0;
    int prev=1;
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
    int curr=0;
    cout<<solve(n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    int adj[n][n];
    for(int i=0;i<e;i++)
    {
        int m,n;
        cin>>m>>n;
        adj[m][n]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
    }
    return 0;
}
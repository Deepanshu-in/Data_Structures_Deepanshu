#include<bits/stdc++.h>
using namespace std;


//add edges to adjacency list
void addEdge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[],int n,int src)
{
    bool visited[n+1];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i:adj[u])
        {
            if(visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main()
{
    //initialising n as number of nodes
    int n=4;
    vector <int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,2,3);

    //BFS
    BFS(adj,n,0);
    return 0;
}
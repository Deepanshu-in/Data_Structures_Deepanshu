#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector <int> adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" :- ";
        for(int j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


void shortestpathBFS(vector<int> adj[],int n,int src,int dest)
{
    bool visited[n];
    int parent[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    queue<int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            while(!visited[v])
            {
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
    }

    vector<int> ans;
    int node=dest;
    while(parent[node]!=-1)
    {
        ans.push_back(parent[node]);
        node=parent[node];
    }

    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}


int main()
{
    int n=9;
    vector<int> adj[n];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,0,5);
    addEdge(adj,5,4);
    addEdge(adj,0,6);
    addEdge(adj,6,7);
    addEdge(adj,7,8);
    addEdge(adj,8,4);
    printList(adj,n);

    shortestpathBFS(adj,9,0,3);
    return 0;
}
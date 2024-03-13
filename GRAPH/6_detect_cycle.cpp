#include<bits/stdc++.h>
using namespace std;


//add edges to adjacency list
void addEdge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool detectCycle(vector<int> adj[],int n,int src)
{
    int parent[n];
    bool visited[n];
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
        for(int x:adj[u])
        {
            if(visited[x]==false)
            {
                q.push(x);
                visited[x]=true;
                parent[x]=u;
            }
            else
            {
                if(parent[u]!=x)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    //initialising n as number of nodes
    int n=4;
    vector <int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    if(detectCycle(adj,n,0)==true)
        cout<<"cycle is present"<<endl;
    else
        cout<<"Absent";
    return 0;
}
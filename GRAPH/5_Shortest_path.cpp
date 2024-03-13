#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


//print adjacency list
void printList(vector<int> adj[],int n)
{
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void shortesPath(vector<int> adj[],int n,int src)
{
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    bool visited[n+1];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> q;
    dist[src]=0;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i:adj[u]){
            if(visited[i]==false)
            {
                dist[i]=dist[u]+1;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
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
    printList(adj,n);
    return 0;
}
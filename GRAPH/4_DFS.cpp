#include<bits/stdc++.h>
using namespace std;


//add edges to adjacency list
void addEdge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


//DFS Recursive function
void DFSrec(vector<int> adj[],int n,int src,bool visited[])
{
    visited[src]=true;
    cout<<src<<" ";
    for(int i:adj[src]){
        if(visited[i]==false){
            DFSrec(adj,n,i,visited);
        }
    }
}


//DFS function to call for recursive code
void DFS(vector<int> adj[],int n,int src)
{
    bool visited[n+1];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false)
        {
            DFSrec(adj,n,i,visited);
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

    //DFS
    DFS(adj,n,0);
    return 0;
}
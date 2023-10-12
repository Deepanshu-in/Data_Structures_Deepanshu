#include<bits/stdc++.h>
using namespace std;


void addEdge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[],int n){
    for(int i=0;i<n;i++){
        cout<<i<<" :- ";
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void BFS(vector<int> adj[],int n,int src){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}


void DFSRec(vector<int> adj[],int n,int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int i: adj[s]){
        if(visited[i]==false){
            DFSRec(adj,n,i,visited);
        }
    }
}

void BFSn(vector<int> adj[],int n,int s){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u]){
            if(visited[x]==false){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

void DFS(vector<int> adj[],int n,int s){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    DFSRec(adj,n,s,visited);
}


bool detectCycleBFSundirected(vector<int> adj[],int n,int src,bool visited[])
{
    int parent[n];
    queue<int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto i:adj[u])
        {
            if(visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
                parent[i]=u;
            }
            else
            {
                if(parent[i]!=u){
                    return true;//cycle detected
                }
            }
        }
        return false;
    }
}

int main()
{
    int n=5;
    vector <int> adj[n];
    int src=0;
    addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);
    printList(adj,n);
    BFSn(adj,n,src);
    cout<<endl;
    DFS(adj,n,src);

    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    return 0;
}
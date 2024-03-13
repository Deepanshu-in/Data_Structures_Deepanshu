#include<bits/stdc++.h>
using namespace std;


//add edges to adjacency list
void addEdge(vector <int> adj[],int u,int v,int indegree[]){
    adj[u].push_back(v);
    indegree[v]++;
}



//Topological sorting using khan's BFS algorithm
void topologicalSort(vector<int> adj[],int n,int indegree[],int src)
{
    queue<int> q;
    
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
}

int main()
{
    //initialising n as number of nodes
    int n=5;
    vector <int> adj[n];
    int indegree[n];
    for(int i=0;i<n;i++){
        indegree[i]=0;
    }
    addEdge(adj,0,3,indegree);
    addEdge(adj,0,2,indegree);
    addEdge(adj,1,3,indegree);
    addEdge(adj,2,3,indegree);
    addEdge(adj,1,4,indegree);

    for(int i=0;i<n;i++){
        cout<<indegree[i]<<" ";
    }

    cout<<endl;
    cout<<"Topological sorting of n will be ;- "<<endl;
    topologicalSort(adj,n,indegree,0);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


void addEdge(vector <int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printEdge(vector <int> adj[],int n)
{
    for(int i=0;i<n;i++){
        for(int j:adj[i]){
            cout<<j<<" ";
        }
    }
}


void DFS(vector<int> adj[],int n){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=true;
    }
    
}

int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    vector <int> adj[n];


    return 0;
}
#include<bits/stdc++.h>
using namespace std;


//add edges to adjacency list
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
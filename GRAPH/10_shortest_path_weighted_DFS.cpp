#include<bits/stdc++.h>
using namespace std;


class Graph
{
    public:
    unordered_map<int,list<pair<int,int> > > adjList;

    void addEdge(int u,int v,int wt, bool direction)
    {
        //direction = 1 (undirected graph)
        //direction = 0 (directed graph)
        adjList[u].push_back({v,wt});
        if(direction==1)
        {
            adjList[v].push_back({u,wt}); 
        }
    }
    
    void printAdjList()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<" "<<j.second<<")";
            }
            cout<<endl;
        }
    }   
};
int main()
{
    Graph g;

    g.addEdge(0,1,1,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);
    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);
    g.addEdge(5,4,1,1);
    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);

    g.printAdjList();
    return 0;
}
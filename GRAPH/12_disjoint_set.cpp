#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    //it is used to find the ultimate parent of the node to reduce the time
    int findUPar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u; //you can do the oposite also
            rank[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    //lets check if 3 and 7 belongs to same parent or not before joining them

    if(ds.findUPar(3)==ds.findUPar(7))
    {
        cout<<"Same"<<endl;
    }
    else 
        cout<<"Not same"<<endl;

    ds.unionByRank(3,7);

    if(ds.findUPar(3)==ds.findUPar(7))
    {
        cout<<"Same"<<endl;
    }
    else 
        cout<<"Not same"<<endl;

    return 0;
}
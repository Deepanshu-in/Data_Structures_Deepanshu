#include<bits/stdc++.h>
using namespace std;


void intersectionSOrted(int a[],int b[],int m,int n){
    unordered_set<int> s(b,b+n);
    for(int i=0;i<m;i++){
        if(s.find(a[i])!=s.end())
            cout<<a[i]<<" ";
    }
}
int main()
{
    int a[6]={10,15,20,25,30,50};
    int b[4]={30,5,15,80};
    intersectionSOrted(a,b,6,4);
    return 0;
}

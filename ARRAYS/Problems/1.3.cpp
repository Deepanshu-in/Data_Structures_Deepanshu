#include<bits/stdc++.h>
using namespace std;


void counts(int arr[],int n)
{
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    for(auto i: m)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}
int main()
{
    int arr[6]={1,2,2,4,2,4};

    counts(arr,6);
    return 0;
}
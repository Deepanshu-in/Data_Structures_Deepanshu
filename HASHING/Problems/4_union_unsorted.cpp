#include<bits/stdc++.h>
using namespace std;

int unionOfSorted(int a[],int b[],int m,int n){
    unordered_set<int>s(a,a+m);
    for(int i=0;i<n;i++){
        s.insert(b[i]);
    }
    return s.size();
}
int main()
{
    int a[4]={15,20,5,15};
    int b[5]={15,15,15,20,10};
    cout<<unionOfSorted(a,b,4,5);
    return 0;
}
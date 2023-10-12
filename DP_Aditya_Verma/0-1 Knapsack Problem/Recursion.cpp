#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
        return 0;
    else{
        if(wt[n-1]<=w){
            return max(val[n-1]+knapSack(wt,val,w-wt[n-1],n-1),knapSack(wt,val,w,n-1));
        }
        else{
            return knapSack(wt,val,w,n-1);
        }
    }
}

int main()
{
    int w=7;
    int wt[4]={2,3,4,5};
    int val[4]={1,4,5,7};
    cout<<knapSack(wt,val,w,4);
    return 0;
}
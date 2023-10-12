#include<bits/stdc++.h>
using namespace std;

void printNto1(int n){
    if(n==1)
        cout<<n<<" ";
    else{
    cout<<n<<" ";
    printNto1(n-1);
    }
}
int main()
{
    printNto1(10);
    return 0;
}
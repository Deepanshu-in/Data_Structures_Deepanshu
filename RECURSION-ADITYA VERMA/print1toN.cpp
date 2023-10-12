#include<bits/stdc++.h>
using namespace std;

void print1toN(int n){
    //base case
    if(n==1)
        cout<<n<<" ";
    else{
        print1toN(n-1); //hyposthesis
        cout<<n<<" "; //induction
    }
}
int main()
{
    print1toN(10);
    return 0;
}
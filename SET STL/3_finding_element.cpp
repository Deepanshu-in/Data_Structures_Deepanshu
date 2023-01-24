#include <bits/stdc++.h>
using namespace std;


int main()
{
    set<int> s;
    s.insert(40);
    s.insert(83);
    s.insert(1);
    s.insert(30);
    auto i=s.find(30);
    if(i==s.end())
    cout<<"Not found"<<endl;
    else
    cout<<"Found"<<endl;
    cout<<endl; 
    //method 2 using count function
    if(s.count(40))
    cout<<"FOund"<<endl;
    else
    cout<<"Not found"<<endl;

return 0;
}
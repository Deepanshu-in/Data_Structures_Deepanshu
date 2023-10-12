#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    int t=s.size();
    while(s.empty()==false){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
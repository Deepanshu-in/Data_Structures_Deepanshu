#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(40);
    s.insert(3);
    s.insert(39);
    s.count(39);
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << (*i) << " ";
    }
    return 0;
}
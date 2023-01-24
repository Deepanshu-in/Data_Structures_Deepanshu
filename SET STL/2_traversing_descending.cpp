#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int, greater<int>> s;
    s.insert(40);
    s.insert(83);
    s.insert(1);
    s.insert(30);
    for (int x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Method 2" << endl;
    // or we can traverse by initialising begin and end
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << (*i) << " ";
    }
    return 0;
}
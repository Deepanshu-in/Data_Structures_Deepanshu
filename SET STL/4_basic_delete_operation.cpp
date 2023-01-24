#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(40);
    s.insert(83);
    s.insert(1);
    s.insert(30);
    cout << "Size of set : " << s.size() << endl;
    cout << "Elements : ";
    for (int x : s)
    {
        cout << x << " ";
    }

    // to remove every element after a certain element
    auto it = s.find(40);//it will remove elements after 40
    s.erase(it, s.end());
     cout << endl;
    cout << endl;
    cout<<"After deleting"<<endl;
    cout << "Size of new set : " << s.size() << endl;
    cout << "New Elements : ";
    for (int x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << endl;

    cout<<"After deleting single element : "<<endl;
    s.erase(30);//to remove single element
    cout << "Size of new set : " << s.size() << endl;
    
    cout << endl;
    cout<<"After deleting all elements : "<<endl;
    s.clear();//to remove all elements
    cout << "Size of new set : " << s.size() << endl;
    return 0;
}
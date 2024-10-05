#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstKElements(queue<int> &q, int k)
{
    if (q.empty() || k > q.size() || k <= 0)
        return;

    stack<int> s;
    for (int i = 0; i < k; ++i)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    int size = q.size();
    for (int i = 0; i < size - k; ++i)
    {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    int k = 3;

    cout << "Original Queue: ";
    printQueue(q);

    reverseFirstKElements(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> s;

    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return nge;
}
vector<int> rightSmallerElement(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> rse(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            rse[i] = s.top();
        }
        s.push(arr[i]);
    }
    return rse;
}

vector<int> rightSmallerOfNextGreater(const vector<int> &arr)
{
    vector<int> nge = nextGreaterElement(arr);
    vector<int> rse(nge.size(), -1);

    for (int i = 0; i < nge.size(); ++i)
    {
        if (nge[i] != -1)
        {
            vector<int> remainingElements(arr.begin() + i + 1, arr.end());
            vector<int> rseTemp = rightSmallerElement(remainingElements);
            for (int j = 0; j < rseTemp.size(); ++j)
            {
                if (remainingElements[j] == nge[i])
                {
                    rse[i] = rseTemp[j];
                    break;
                }
            }
        }
    }

    return rse;
}

int main()
{
    vector<int> arr = {5, 1, 9, 2, 5, 1, 7};
    vector<int> result = rightSmallerOfNextGreater(arr);
    cout << "Right Smaller of Next Greater for each element: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        return ((n >> k) & 1) != 0;
    }
};

int main()
{
    long long n;
    cin >> n; // input n
    int k;
    cin >> k; // bit number k
    Solution obj;
    if (obj.checkKthBit(n, k))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

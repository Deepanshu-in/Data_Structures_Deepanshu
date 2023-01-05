#include <bits/stdc++.h>
using namespace std;
bool isSub(string s1, string s2, int n, int m)
{
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (s1[i] == s2[j])
            j++;
    }
    return (j == m);
}
int main()
{
    string s1 = "ABCDE";
    string s2 = "ACDE";
    int j = isSub(s1, s2, 5, 4);
    cout << j;
    return 0;
}
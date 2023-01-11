#include <bits/stdc++.h>
using namespace std;

void mergeArray(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
            cout << a[i++] << " ";
        else
            cout << b[j++] << " ";
    }
    while (i < m)
        cout << a[i++] << " ";
    while (j < n)
        cout << b[j++] << " ";
}
int main()
{
    int a[5] = {1, 2, 3, 6, 9};
    int b[6] = {5, 7, 8, 99, 112, 117};
    mergeArray(a, b, 5, 6);
    return 0;
}
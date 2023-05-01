#include <bits/stdc++.h>
using namespace std;

int maxVal(int arr[], int n)
{
    int res = arr[1] - arr[0];
    int minVal = arr[0];
    for (int j = 1; j < n; j++)
    {
        res = max(res, arr[j] - minVal);
        minVal = min(minVal, arr[j]);
    }
    return res;
}
int main()
{
    int arr[6] = {2, 3, 6, 8, 9, 0};
    int j = maxVal(arr, 6);
    cout << j;

    return 0;
}
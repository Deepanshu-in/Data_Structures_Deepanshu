#include <bits/stdc++.h>
using namespace std;

int longestEvenOdd(int arr[], int n)
{
    int res = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 == 0 && arr[i - 1] % 2 == 1 || arr[i] % 2 == 1 && arr[i - 1] % 2 == 0)
        {
            count++;
            res = max(res, count);
        }
        else
            count = 1;
    }
    return res;
}

int main()
{
    int arr[6] = {5, 10, 20, 6, 3, 8};
    int j = longestEvenOdd(arr, 6);
    cout << j;
    return 0;
}
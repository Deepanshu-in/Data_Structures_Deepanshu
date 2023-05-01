#include <bits/stdc++.h>
using namespace std;

void leader(int arr[], int n)
{
    int res;
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= curr_ldr)
        {
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 6, 5, 2};
    leader(arr, 7);
    return 0;
}
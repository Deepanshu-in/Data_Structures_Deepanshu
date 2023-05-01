#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        high--;
        low++;
    }
}

void rotateArr(int arr[], int d, int n)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int d = 2;
    int n = 5;

    rotateArr(arr, d, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
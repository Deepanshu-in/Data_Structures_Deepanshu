#include <iostream>
using namespace std;
/*
Naive solution to the problem

void firstOcc(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << i;
            break;
        }
    }
}
*/

int firstOcc(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] > x)
        return firstOcc(arr, low, mid - 1, x);
    else if (arr[mid] < x)
        return firstOcc(arr, mid + 1, high, x);

    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return firstOcc(arr, low, mid - 1, x);
    }
}
int main()
{
    int arr[5] = {1, 1, 2, 2, 4};
    int j = firstOcc(arr, 0, 4, 2);
    cout << j;
    return 0;
}
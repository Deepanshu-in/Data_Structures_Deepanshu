#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int element)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[5] = {11, 22, 33, 44, 55};
    int j = binarySearch(arr, 5, 22);
    cout << j;
}
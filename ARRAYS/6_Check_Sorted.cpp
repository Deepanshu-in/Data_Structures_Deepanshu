#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
            continue;
        else
            return false;
    }
    return true;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {34, 45, 2, 5, 6};
    int j = isSorted(arr, 5);
    int k = isSorted(arr2, 5);
    cout << j << endl;
    cout << k << endl;

    return 0;
}
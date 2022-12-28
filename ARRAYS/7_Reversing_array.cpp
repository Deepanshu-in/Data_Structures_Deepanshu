#include <iostream>
using namespace std;

void reverseArr(int arr[], int n)
{
    int high = n - 1;
    int low = 0;
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
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
    int arr[5] = {5, 4, 3, 2, 1};
    reverseArr(arr, 5);
    printArr(arr, 5);

    return 0;
}
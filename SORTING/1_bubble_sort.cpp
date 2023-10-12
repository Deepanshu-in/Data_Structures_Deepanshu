#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            if (swapped == false)
                break;
        }
    }
}

void pritnArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    cout << "Before sort" << endl;
    pritnArr(arr, 5);
    bubbleSort(arr, 5);
    cout << endl;
    cout << "After sort" << endl;
    pritnArr(arr, 5);

    return 0;
}
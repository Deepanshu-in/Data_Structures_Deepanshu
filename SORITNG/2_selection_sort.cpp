#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
                swap(arr[i], arr[min_ind]);
            }
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
    selectionSort(arr, 5);
    cout << endl;
    cout << "After sort" << endl;
    pritnArr(arr, 5);
    return 0;
}
#include <iostream>
using namespace std;

int secMax(int arr[], int n)
{
    int res = -1, largest = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int arr[5] = {1, 2, 90, 38, 5};
    int j = secMax(arr, 5);
    cout << "Second largest element is at index :- " << j;
    return 0;
}
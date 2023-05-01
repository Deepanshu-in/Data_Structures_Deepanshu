#include <iostream>
using namespace std;

int secMax(int a[], int n)
{
    int largest = 0;
    int res = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[largest])
        {
            res = largest;
            largest = i;
        }
        else if (a[i] != a[largest])
        {
            if (res == -1 || a[i] > a[res])
                res = i;
        }
    }
    return res;
}
int main()
{
    int arr[5] = {5, 399, 885, 5, 222};
    int j = secMax(arr, 5);
    cout << "Second largest element is at index :- " << j;
    return 0;
}
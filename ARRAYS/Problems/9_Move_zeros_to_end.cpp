#include <iostream>
using namespace std;

void moveZero(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[cnt]);
            cnt++;
        }
    }
}
int main()
{
    int arr[5] = {1, 0, 9, 0, 8};

    moveZero(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
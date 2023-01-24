#include <iostream>
using namespace std;

int maxEle(int arr[], int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int n = 5;
    int arr[5] = {1, 2, 76, 9, 5};
    int j = maxEle(arr, n);
    cout << "Maximum Element :- " << j;

    return 0;
}
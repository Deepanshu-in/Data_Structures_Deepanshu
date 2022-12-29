#include <iostream>
using namespace std;

int maxProfit(int arr[], int n)
{
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            profit += (arr[i] - arr[i - 1]);
    }
    return profit;
}
int main()
{
    int arr[5] = {1, 5, 3, 5, 9};
    int j = maxProfit(arr, 5);
    cout << j;
    return 0;
}
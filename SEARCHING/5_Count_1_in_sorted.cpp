#include <iostream>
using namespace std;
int cntOne(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i & j == 1)
                cnt++;
        }
    }
    return cnt + 1;
}
int main()
{
    int arr[5] = {0, 1, 1, 1, 1};
    int j = cntOne(arr, 5);
    cout << j;
    return 0;
}
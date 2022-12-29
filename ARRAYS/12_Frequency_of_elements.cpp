#include <iostream>
using namespace std;

void frequency(int arr[], int n)
{
    int cnt = 1;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i++] == arr[j++])
                cnt++;
            else
                break;
        }
    }
}
int main()
{
    int arr[5] = {1, 2, 2, 4, 2};

    return 0;
}
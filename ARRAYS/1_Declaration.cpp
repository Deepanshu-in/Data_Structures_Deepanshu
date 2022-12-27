#include <iostream>
using namespace std;

int main()
{
    // Stack Allocated
    // Fixed size
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int arr[] = {1, 2, 3, 4, 5};
    int arr[n];

    // Heap Allocated
    // Dynamic Array
    int s;
    cin >> s;
    int *arr = new int[s];

    return 0;
}
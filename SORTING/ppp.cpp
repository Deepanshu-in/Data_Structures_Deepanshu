// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int> &arr, int x, int n)
// {
//     int cnt = 0;
//     unordered_map<int, int> m;

//     // Storing the elements and their indices in the map
//     for (int i = 0; i < n; i++)
//     {
//         m[arr[i]] = i;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int target = abs(arr[i] - x);
//         int divi = (arr[i] - target);
//         if (divi % x == 0)
//         {
//             if (m.find(arr[i]) != m.end())
//                 cnt++;
//         }
//     }

//     return cnt;
// }

// int main()
// {
//     int x;
//     cin >> x;

//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // Call the solve function and print the result
//     int result = solve(arr, x, n);
//     cout << "Number of pairs with sum " << x << ": " << result << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int findPairs(vector<int> &arr, int x, int n)
{
    int cnt = 0;
    vector<int> remainderCount(x, 0); // Array to store the count of each remainder

    // Count remainders of all elements in the array when divided by x
    for (int i = 0; i < n; i++)
    {
        int remainder = arr[i] % x;
        remainderCount[remainder]++;
    }

    // Case 1: Pairs where both elements have remainder 0
    cnt += (remainderCount[0] * (remainderCount[0] - 1)) / 2; // nC2 = n * (n-1) / 2 for pairs

    // Case 2: Pairs where remainders sum to x
    for (int i = 1; i <= x / 2; i++)
    {
        if (i != x - i)
        {                                                     // Ensure remainders are different
            cnt += remainderCount[i] * remainderCount[x - i]; // Pairs (i, x-i)
        }
    }

    // Case 3: Special case where remainder is exactly half of x
    if (x % 2 == 0)
    {
        cnt += (remainderCount[x / 2] * (remainderCount[x / 2] - 1)) / 2; // nC2 for this case
    }

    return cnt;
}

int main()
{
    int x;
    cin >> x; // Input x (sum divisor)

    int n;
    cin >> n; // Input the number of products

    vector<int> arr(n); // Store the cost of products
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the cost of each product
    }

    // Call the findPairs function and print the result
    int result = findPairs(arr, x, n);
    cout << "Number of pairs with sum divisible by " << x << ": " << result << endl;

    return 0;
}

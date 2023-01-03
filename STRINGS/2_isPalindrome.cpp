#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
int main()
{
    string str = "ABBA";
    int j = isPalindrome(str);
    cout << j;

    return 0;
}
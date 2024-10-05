#include <bits/stdc++.h>
using namespace std;

bool canDefeat(vector<int> &player1, vector<int> &player2)
{
    vector<int> p1 = player1;
    vector<int> p2 = player2;
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    int wins = 0;
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        if (p1[i] > p2[j])
        {
            wins++;
            j++;
        }
    }
    return wins >= 2;
}

int findCapableWinners(vector<int> power_type_a, vector<int> power_type_b, vector<int> power_type_c)
{
    int n = power_type_a.size();
    vector<vector<int>> players(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        players[i] = {power_type_a[i], power_type_b[i], power_type_c[i]};
    }

    int capableWinners = 0;

    for (int i = 0; i < n; i++)
    {
        bool canDefeatAll = true;
        for (int j = 0; j < n; j++)
        {
            if (i != j && !canDefeat(players[i], players[j]))
            {
                canDefeatAll = false;
                break;
            }
        }
        if (canDefeatAll)
        {
            capableWinners++;
        }
    }

    return capableWinners;
}

int main()
{
    // Example Input
    vector<int> power_a = {3, 4, 1, 16};
    vector<int> power_b = {2, 11, 5, 6};
    vector<int> power_c = {8, 7, 9, 10};

    // Call the function and print the result
    cout << findCapableWinners(power_a, power_b, power_c) << endl;

    return 0;
}
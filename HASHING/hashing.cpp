#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> hashTable;

    int numbers[] = {12, 18, 13, 2, 3, 23, 5, 15};
    int n = 8;

    for (int i = 0; i < n; ++i)
    {
        hashTable.insert(numbers[i] % 10);
    }

    cout << "Values in the hash table: ";
    for (const int &num : hashTable)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

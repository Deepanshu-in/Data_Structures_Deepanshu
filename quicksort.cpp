#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 20;
const int DELAY_MS = 100;
const int BAR_WIDTH = 3;
const char BAR_CHAR = '#';
const char CURRENT_MIN_CHAR = '*';
const char COMPARING_CHAR = '?';
const char SWAPPING_CHAR = 'X';
const char SORTED_CHAR = '@';

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void delay()
{
    this_thread::sleep_for(chrono::milliseconds(DELAY_MS));
}

void visualizeArray(const vector<int> &arr,
                    const vector<char> &markers,
                    int currentPos = -1,
                    int minPos = -1,
                    int comparing = -1,
                    bool swapping = false)
{

    clearScreen();

    int maxVal = *max_element(arr.begin(), arr.end());

    cout << "SelectionSort Visualization" << endl;
    cout << "==========================" << endl
         << endl;

    cout << BAR_CHAR << " - Unsorted element  "
         << CURRENT_MIN_CHAR << " - Current minimum  "
         << COMPARING_CHAR << " - Comparing  "
         << SORTED_CHAR << " - Sorted element" << endl
         << endl;

    int maxHeight = 15;

    for (int h = maxHeight; h > 0; h--)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int barHeight = static_cast<int>((static_cast<double>(arr[i]) / maxVal) * maxHeight);

            if (barHeight >= h)
            {
                char displayChar = markers[i];
                for (int w = 0; w < BAR_WIDTH; w++)
                {
                    cout << displayChar;
                }
            }
            else
            {
                for (int w = 0; w < BAR_WIDTH; w++)
                {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < arr.size() * BAR_WIDTH; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << setw(BAR_WIDTH) << i;
    }
    cout << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << setw(BAR_WIDTH) << arr[i];
    }
    cout << endl
         << endl;

    if (currentPos >= 0)
    {
        cout << "Current position: " << currentPos << endl;
    }

    if (minPos >= 0)
    {
        cout << "Current minimum: arr[" << minPos << "] = " << arr[minPos] << endl;
    }

    if (comparing >= 0)
    {
        cout << "Comparing with: arr[" << comparing << "] = " << arr[comparing] << endl;
    }

    if (swapping && currentPos >= 0 && minPos >= 0)
    {
        cout << "Swapping arr[" << currentPos << "] = " << arr[currentPos]
             << " and arr[" << minPos << "] = " << arr[minPos] << endl;
    }

    delay();
}

void selectionSort(vector<int> &arr)
{
    vector<char> markers(arr.size(), BAR_CHAR);
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;

        markers[i] = COMPARING_CHAR;
        visualizeArray(arr, markers, i, minIdx);

        markers[minIdx] = CURRENT_MIN_CHAR;

        for (int j = i + 1; j < n; j++)
        {
            markers[j] = COMPARING_CHAR;
            visualizeArray(arr, markers, i, minIdx, j);

            if (arr[j] < arr[minIdx])
            {
                markers[minIdx] = BAR_CHAR;
                minIdx = j;
                markers[minIdx] = CURRENT_MIN_CHAR;
                visualizeArray(arr, markers, i, minIdx);
            }

            markers[j] = BAR_CHAR;
        }

        if (minIdx != i)
        {
            markers[i] = SWAPPING_CHAR;
            markers[minIdx] = SWAPPING_CHAR;
            visualizeArray(arr, markers, i, minIdx, -1, true);

            swap(arr[i], arr[minIdx]);

            visualizeArray(arr, markers, i, minIdx);

            markers[minIdx] = BAR_CHAR;
        }

        markers[i] = SORTED_CHAR;
        visualizeArray(arr, markers, i);
    }

    markers[n - 1] = SORTED_CHAR;
    visualizeArray(arr, markers);
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 99);

    vector<int> array(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = dist(gen);
    }

    vector<char> markers(ARRAY_SIZE, BAR_CHAR);

    cout << "Initial array:" << endl;
    visualizeArray(array, markers);

    cout << "Press Enter to start SelectionSort...";
    cin.get();

    selectionSort(array);

    cout << "Sorting completed!" << endl;
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <utility>

using namespace std;

/**
 * @brief Extract odd-indexed characters (1-indexed positions) from the input string.
 *
 * Ye function input qstring ke un characters ko extract karta hai jo odd positions (1, 3, 5, …)
 * par hote hain. (Yahan, 0-indexed loop me index 0, 2, 4,... ko odd mana gaya hai)
 *
 * @param input The input string.
 * @param oddChars Reference to the string where extracted characters are stored.
 * @param mtx Mutex for thread-safe update of oddChars.
 */
void extractOddCharacters(const string &input, string &oddChars, mutex &mtx)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        // 0-indexed even indices correspond to odd positions (1-indexed)
        if (i % 2 == 0)
        {
            lock_guard<mutex> lock(mtx);
            oddChars.push_back(input[i]);
        }
    }
}

/**
 * @brief Extract even-indexed characters (1-indexed positions) from the input string.
 *
 * Ye function input string ke un characters ko extract karta hai jo even positions (2, 4, 6, …)
 * par hote hain. (Yahan, 0-indexed loop me index 1, 3, 5,... ko even mana gaya hai)
 *
 * @param input The input string.
 * @param evenChars Reference to the string where extracted characters are stored.
 * @param mtx Mutex for thread-safe update of evenChars.
 */
void extractEvenCharacters(const string &input, string &evenChars, mutex &mtx)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        // 0-indexed odd indices correspond to even positions (1-indexed)
        if (i % 2 == 1)
        {
            lock_guard<mutex> lock(mtx);
            evenChars.push_back(input[i]);
        }
    }
}

/**
 * @brief Computes the sum of ASCII values for all characters in the given string.
 *
 * @param chars The string containing characters.
 * @return int The sum of ASCII values.
 */
int computeAsciiSum(const string &chars)
{
    int sum = 0;
    for (char ch : chars)
    {
        sum += static_cast<int>(ch);
    }
    return sum;
}

/**
 * @brief Counts the vowels and consonants in a given string.
 *
 * Ye function alphabetic characters ke liye vowel aur consonant count return karta hai.
 *
 * @param chars The string containing characters.
 * @return pair<int, int> First element is vowel count, second element is consonant count.
 */
pair<int, int> countVowelsAndConsonants(const string &chars)
{
    int vowelCount = 0, consonantCount = 0;
    auto isVowel = [](char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    };

    for (char ch : chars)
    {
        if (isalpha(ch))
        {
            if (isVowel(ch))
                vowelCount++;
            else
                consonantCount++;
        }
    }
    return {vowelCount, consonantCount};
}

/**
 * @brief Returns the reversed version of the input string.
 *
 * @param str The string to be reversed.
 * @return string The reversed string.
 */
string reverseString(const string &str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}

/**
 * @brief Displays the results of various computations based on the user's choice.
 *
 * Option ke hisaab se yeh function ASCII sum, vowel/consonant count, aur reversed strings print karta hai.
 *
 * @param oddChars The string containing odd-positioned characters.
 * @param evenChars The string containing even-positioned characters.
 * @param option The user selected option (1, 2, 3, or 4).
 */
void displayResults(const string &oddChars, const string &evenChars, int option)
{
    cout << "\n--- Parinaam ---\n";

    if (option == 1 || option == 4)
    {
        int asciiSumOdd = computeAsciiSum(oddChars);
        int asciiSumEven = computeAsciiSum(evenChars);
        cout << "Odd characters ka ASCII sum: " << asciiSumOdd << endl;
        cout << "Even characters ka ASCII sum: " << asciiSumEven << endl;
    }

    if (option == 2 || option == 4)
    {
        auto [vowelCountOdd, consonantCountOdd] = countVowelsAndConsonants(oddChars);
        auto [vowelCountEven, consonantCountEven] = countVowelsAndConsonants(evenChars);
        cout << "Odd characters me vowels: " << vowelCountOdd << " aur consonants: " << consonantCountOdd << endl;
        cout << "Even characters me vowels: " << vowelCountEven << " aur consonants: " << consonantCountEven << endl;
    }

    if (option == 3 || option == 4)
    {
        string revOdd = reverseString(oddChars);
        string revEven = reverseString(evenChars);
        cout << "Odd characters ka reverse: " << revOdd << endl;
        cout << "Even characters ka reverse: " << revEven << endl;
    }
}

int main()
{
    try
    {
        // User se input string liya ja raha hai.
        cout << "Kripya ek string input karein: ";
        string input;
        getline(cin, input);

        if (input.empty())
        {
            throw invalid_argument("Input string cannot be empty.");
        }

        // Odd aur Even characters store karne ke liye strings
        string oddChars, evenChars;
        mutex mtx; // Thread-safe modifications ke liye mutex

        // Alag threads bana ke odd aur even characters extract kiye ja rahe hain
        thread t1(extractOddCharacters, cref(input), ref(oddChars), ref(mtx));
        thread t2(extractEvenCharacters, cref(input), ref(evenChars), ref(mtx));

        // Threads ke complete hone ka intazaar
        t1.join();
        t2.join();

        // Extracted characters ko display karna
        cout << "Odd position ke characters: " << oddChars << endl;
        cout << "Even position ke characters: " << evenChars << endl;

        // User ke liye options display karna
        cout << "\nKripya ek option chunein:\n";
        cout << "1. ASCII sum nikalne ke liye\n";
        cout << "2. Vowel aur consonant count nikalne ke liye\n";
        cout << "3. Reverse string nikalne ke liye\n";
        cout << "4. Sabhi computations chalane ke liye\n";
        cout << "Aapka vikalp chunein (1/2/3/4): ";

        int option;
        cin >> option;

        // Chune gaye option ke hisaab se results display karna
        displayResults(oddChars, evenChars, option);
    }
    catch (const exception &ex)
    {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}
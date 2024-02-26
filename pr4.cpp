#include <algorithm> 
#include<iostream>
#include <random>
#include<string>

using namespace std;

string removeVowels(const string& str)
{
    string result;
    for (char chr : str) {
        if (!(chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u' ||
            chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U' )) {
            result += chr;
        }
    }
    return result;
}

string removeConsonants(const string& str)
{
    string result;
    for (char ch : str) {
        if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ||
            !isalpha(ch)) {
            result += ch;
        }
    }
    return result;
}

string shuffle(const string& str)
{
    string result = str;
    shuffle(result.begin(), result.end(), default_random_engine(time(nullptr)));
    return result;
}

int main()
{
    int ch;
    string str, result;
    do
    {
        cout << "Enter your word: ";
        cin >> str;
        cout << "Please, choose action" << endl;
        cout << "1. Reverse a word" << endl;
        cout << "2. Print a word without vowels" << endl;
        cout << "3. Print a word without consonants" << endl;
        cout << "4. Randomly scatter the letters of a given word" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            reverse(str.begin(), str.end());
            cout << "\n" << str << endl;
            break;
        case 2:
            result = removeVowels(str);
            cout << "\n" << result << endl;
            break;
        case 3:
            result = removeConsonants(str);
            cout << "\n" << result << endl;
            break;
        case 4:
            result = shuffle(str);
            cout << "\n" << result << endl;
            break;
        default:
            break;
        }
    } while (ch != 0);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    int n = text.length(), m = pattern.length();
    bool found = false;
    // Naive string matching: slide pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }
    if (!found)
        cout << "not found" << endl;
    return 0;
}
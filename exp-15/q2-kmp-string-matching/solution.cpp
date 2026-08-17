#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computeLPS(const string &p)
{
    int m = p.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len != 0)
        {
            len = lps[len - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
    return lps;
}

int main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    int n = text.length(), m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    bool found = false;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if (!found)
        cout << "not found" << endl;
    return 0;
}

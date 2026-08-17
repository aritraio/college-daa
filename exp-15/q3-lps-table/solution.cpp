#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string pattern;
    getline(cin, pattern);
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
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
    cout << "LPS:";
    for (i = 0; i < m; i++)
        cout << " " << lps[i];
    cout << endl;
    return 0;
}

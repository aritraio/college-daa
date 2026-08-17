#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    bool found = false;
    // Brute force: try every pair (i, j) with i < j
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == s)
            {
                cout << "(" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }
    if (!found)
        cout << "No pairs found" << endl;
    return 0;
}
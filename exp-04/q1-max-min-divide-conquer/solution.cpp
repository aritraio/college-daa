#include <iostream>
using namespace std;

// Divide and conquer: find min and max in a[lo..hi]
void findMinMax(int a[], int lo, int hi, int &min, int &max)
{
    if (lo == hi)
    {
        min = max = a[lo];
        return;
    }
    if (hi == lo + 1)
    {
        if (a[lo] < a[hi])
        {
            min = a[lo];
            max = a[hi];
        }
        else
        {
            min = a[hi];
            max = a[lo];
        }
        return;
    }
    int mid = (lo + hi) / 2;
    int minL, maxL, minR, maxR;
    findMinMax(a, lo, mid, minL, maxL);
    findMinMax(a, mid + 1, hi, minR, maxR);
    min = minL < minR ? minL : minR;
    max = maxL > maxR ? maxL : maxR;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int min, max;
    findMinMax(a, 0, n - 1, min, max);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}
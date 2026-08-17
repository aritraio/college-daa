#include <iostream>
#include <climits>
using namespace std;

void findMinMax(int arr[], int n, int &min, int &max)
{
    if (n == 1)
    {
        min = max = arr[0];
        return;
    }
    findMinMax(arr, n - 1, min, max);
    if (arr[n - 1] < min)
        min = arr[n - 1];
    if (arr[n - 1] > max)
        max = arr[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int min = INT_MAX, max = INT_MIN;
    findMinMax(arr, n, min, max);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n, key;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    // Linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return 0;
        }
    }

    cout << "Element not found" << endl;
    return 0;
}
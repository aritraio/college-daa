#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int profit;
};

int main() {
    int n;
    double W;
    cin >> n >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
    }

    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return (double)a.profit / a.weight > (double)b.profit / b.weight;
    });

    double total = 0.0;
    for (const Item &item : items) {
        if (item.weight <= W) {
            total += item.profit;
            W -= item.weight;
        } else {
            total += item.profit * (W / item.weight);
            W = 0;
        }
    }

    cout << fixed << setprecision(2) << total << endl;
    return 0;
}
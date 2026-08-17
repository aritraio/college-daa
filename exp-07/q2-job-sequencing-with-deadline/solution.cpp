#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        maxD = max(maxD, jobs[i].deadline);
    }

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return a.profit > b.profit;
    });

    vector<int> slot(maxD, 0);
    int total = 0;
    for (const Job &job : jobs) {
        for (int j = job.deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = job.id;
                total += job.profit;
                break;
            }
        }
    }

    cout << "Selected jobs:";
    for (int s : slot) {
        if (s != 0) cout << " " << s;
    }
    cout << "\nTotal profit: " << total << endl;
    return 0;
}
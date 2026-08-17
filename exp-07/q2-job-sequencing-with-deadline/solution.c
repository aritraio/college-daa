#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int cmp(const void *a, const void *b) {
    const Job *x = (const Job *)a;
    const Job *y = (const Job *)b;
    return y->profit - x->profit;
}

int main() {
    int n, i, j, maxD = 0;
    scanf("%d", &n);

    Job jobs[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > maxD) maxD = jobs[i].deadline;
    }

    qsort(jobs, n, sizeof(Job), cmp);

    int slot[maxD];
    for (i = 0; i < maxD; i++) slot[i] = 0;

    int total = 0;
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = jobs[i].id;
                total += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected jobs:");
    for (i = 0; i < maxD; i++) {
        if (slot[i] != 0) printf(" %d", slot[i]);
    }
    printf("\nTotal profit: %d\n", total);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int profit;
} Item;

int cmp(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;
    double r1 = (double)x->profit / x->weight;
    double r2 = (double)y->profit / y->weight;
    if (r1 > r2) return -1;
    if (r1 < r2) return 1;
    return 0;
}

int main() {
    int n, i;
    double W;
    scanf("%d %lf", &n, &W);

    Item items[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }

    qsort(items, n, sizeof(Item), cmp);

    double total = 0.0;
    for (i = 0; i < n && W > 0; i++) {
        if (items[i].weight <= W) {
            total += items[i].profit;
            W -= items[i].weight;
        } else {
            total += items[i].profit * (W / items[i].weight);
            W = 0;
        }
    }

    printf("%.2f\n", total);
    return 0;
}
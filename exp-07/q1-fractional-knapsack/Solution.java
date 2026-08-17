import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Solution {
    static class Item {
        int weight;
        int profit;

        Item(int weight, int profit) {
            this.weight = weight;
            this.profit = profit;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double W = sc.nextDouble();

        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            items[i] = new Item(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(items, new Comparator<Item>() {
            public int compare(Item a, Item b) {
                double r1 = (double) a.profit / a.weight;
                double r2 = (double) b.profit / b.weight;
                return Double.compare(r2, r1);
            }
        });

        double total = 0.0;
        for (int i = 0; i < n && W > 0; i++) {
            if (items[i].weight <= W) {
                total += items[i].profit;
                W -= items[i].weight;
            } else {
                total += items[i].profit * (W / items[i].weight);
                W = 0;
            }
        }

        System.out.printf("%.2f%n", total);
        sc.close();
    }
}
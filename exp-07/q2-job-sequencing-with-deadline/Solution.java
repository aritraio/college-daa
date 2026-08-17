import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Solution {
    static class Job {
        int id;
        int deadline;
        int profit;

        Job(int id, int deadline, int profit) {
            this.id = id;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Job[] jobs = new Job[n];
        int maxD = 0;
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(sc.nextInt(), sc.nextInt(), sc.nextInt());
            if (jobs[i].deadline > maxD) maxD = jobs[i].deadline;
        }

        Arrays.sort(jobs, new Comparator<Job>() {
            public int compare(Job a, Job b) {
                return b.profit - a.profit;
            }
        });

        int[] slot = new int[maxD];
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline - 1; j >= 0; j--) {
                if (slot[j] == 0) {
                    slot[j] = jobs[i].id;
                    total += jobs[i].profit;
                    break;
                }
            }
        }

        System.out.print("Selected jobs:");
        for (int i = 0; i < maxD; i++) {
            if (slot[i] != 0) System.out.print(" " + slot[i]);
        }
        System.out.println();
        System.out.println("Total profit: " + total);
        sc.close();
    }
}
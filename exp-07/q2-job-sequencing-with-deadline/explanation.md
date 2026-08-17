# Experiment 7: Greedy Algorithms — Q2. Job Sequencing with Deadline

## Problem Statement
Given `n` jobs, each with a job id, a deadline and a profit, select and schedule a subset of jobs on a single machine so that the total profit is maximized. Each job takes exactly one unit of time and must be completed before (or by) its deadline. The program reads `n`, then `id deadline profit` for each job, and prints the sequence of selected jobs followed by the total profit.

## Algorithm & Approach
- Sort all jobs by profit in descending order — the greedy choice is to always consider the highest-profit job first.
- Maintain a time slot array of size equal to the maximum deadline; slot `j` represents time unit `j + 1`.
- For each job, try to place it in the latest free slot that is ≤ its deadline, so earlier slots stay available for other jobs.
- If such a slot is found, schedule the job there and add its profit; otherwise the job is skipped.
- Finally print the job ids present in the slots (in increasing time order) and the total profit.

## Pseudocode
```
read n
for i = 1 to n:
    read id[i], deadline[i], profit[i]
maxD = maximum deadline
sort jobs by profit in descending order
slot[1 .. maxD] = empty
total = 0
for each job in sorted order:
    for j = deadline down to 1:
        if slot[j] is empty:
            slot[j] = id
            total = total + profit
            break
print "Selected jobs:" followed by non-empty slots in order
print "Total profit: total"
```

## Complexity Analysis
- **Time Complexity:** O(n²) — O(n log n) for sorting plus O(n · maxD) for assigning jobs to slots.
- **Space Complexity:** O(n) — for storing the jobs and the slot array.

## Sample Input & Output
```
Input:
4
1 2 50
2 1 60
3 2 20
4 3 30

Output:
Selected jobs: 2 1 4
Total profit: 140
```
# Experiment 1: Recursion Basics — Q1. Tower of Hanoi

## Problem Statement
Write a program to solve the Tower of Hanoi problem using recursion. There are `n` disks of decreasing size stacked on peg **A**. Move all disks to peg **C** using peg **B** as auxiliary, obeying the rules: only one disk moves at a time, and a larger disk may never sit on top of a smaller disk. The program reads `n` (number of disks) and prints every move in the form `Move disk X from A to C`, followed by the total number of moves.

## Algorithm & Approach
- The classic recursive strategy breaks the problem into three steps:
  1. Move the top `n-1` disks from source peg to auxiliary peg.
  2. Move the largest disk (disk `n`) directly from source peg to destination peg.
  3. Move the `n-1` disks from auxiliary peg to destination peg.
- **Base case:** a single disk is moved directly from source to destination.
- A counter is incremented on every printed move so the program can report the total number of moves.

## Pseudocode
```
function TowerOfHanoi(n, from, to, aux, count):
    if n == 1:
        print "Move disk 1 from from to to"
        count += 1
        return
    TowerOfHanoi(n - 1, from, aux, to, count)
    print "Move disk n from from to to"
    count += 1
    TowerOfHanoi(n - 1, aux, to, from, count)

read n
count = 0
TowerOfHanoi(n, 'A', 'C', 'B', count)
print "Total moves: count"
```

## Complexity Analysis
- **Time Complexity:** O(2ⁿ) — every call spawns two recursive calls, giving 2ⁿ − 1 total moves.
- **Space Complexity:** O(n) — the recursion stack holds at most `n` activation records.

## Sample Input & Output
```
Input:
3

Output:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total moves: 7
```
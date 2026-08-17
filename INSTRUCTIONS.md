# Contribution & Implementation Instructions

This document specifies the folder organization, file requirements, and the complete list of lab experiment questions for implementing solutions.

---

## 📁 Folder Structure Requirements

For every experiment and its respective sub-questions:
1. Create a dedicated folder for each experiment (e.g., `exp-01/`).
2. Inside each experiment folder, create a dedicated folder for each question/exercise (e.g., `q1-tower-of-hanoi/`).

---

## 📄 File Requirements per Question

Each question directory **must** contain:

### 1. Multi-Language Implementations
- `solution.c` - C implementation
- `solution.cpp` - C++ implementation
- `Solution.java` - Java implementation
- `solution.py` - Python implementation
- `solution.js` - JavaScript implementation
- `solution.go` - Go implementation

### 2. Explanation & Documentation
- `explanation.md` - Must include:
  - **Problem Statement**
  - **Algorithm & Approach**
  - **Pseudocode**
  - **Complexity Analysis**: Time Complexity & Space Complexity
  - **Sample Input & Output**

---

## 🌳 Example Directory Tree

```text
DAA/
├── README.md
├── INSTRUCTIONS.md
├── exp-01/
│   ├── q1-tower-of-hanoi/
│   │   ├── solution.c
│   │   ├── solution.cpp
│   │   ├── Solution.java
│   │   ├── solution.py
│   │   ├── solution.js
│   │   ├── solution.go
│   │   └── explanation.md
│   ├── q2-max-min-recursion/
│   │   └── ...
│   ├── q3-factorial-fibonacci-recursion/
│   │   └── ...
│   └── q4-gcd-recursion/
│       └── ...
├── exp-02/
│   ├── q1-linear-search/
│   │   └── ...
│   └── q2-binary-search-recursion/
│       └── ...
└── ...
```

---

## 📋 Complete List of Lab Questions

### Experiment 1: Recursion Basics
- **1.i.** Write a program to solve Tower of Hanoi using recursion.
- **1.ii.** Write a program to find maximum and minimum elements using recursion.
- **1.iii.** Write a recursive program to generate factorial/Fibonacci.
- **1.iv.** Write a recursive program to find GCD of two numbers.

### Experiment 2: Searching Algorithms
- **2.i.** Write a C program to perform Linear search.
- **2.ii.** Implement Binary Search using recursion.

### Experiment 3: Divide & Conquer Sorting
- **3.i.** Write a program in C which can sort between $n$ numbers of elements using Merge sort technique.
- **3.ii.** Write a program in C which can sort between $n$ numbers of elements using Quick sort technique.
- **3.iii.** Write a C program to perform Heap Sort technique.

### Experiment 4: Brute-Force & Divide and Conquer
- **4.i.** Write a program to find the maximum and minimum element using divide and conquer.
- **4.ii.** Write a brute-force program to find all pairs with a given sum.
- **4.iii.** Write a brute-force program for naïve string matching.
- **4.iv.** Write a brute-force program for selection sort.

### Experiment 5: Matrix Multiplication (Divide and Conquer)
- **5.i.** Implement matrix multiplication using divide and conquer.

### Experiment 6: Strassen’s Algorithm
- **6.i.** Implement Strassen’s Matrix Multiplication Algorithm.

### Experiment 7: Greedy Algorithms
- **7.i.** Implement Fractional Knapsack Problem using greedy method.
- **7.ii.** Implement Job Sequencing with Deadline.

### Experiment 8: 0/1 Knapsack (Dynamic Programming)
- **8.i.** Implement 0/1 Knapsack Problem using Dynamic Programming.

### Experiment 9: Dynamic Programming & Backtracking
- **9.i.** Implement Matrix Chain Multiplication using Dynamic Programming.
- **9.ii.** Implement N-Queens Problem using Backtracking.

### Experiment 10: Graph Traversal & Representations
- **10.i.** Write a C program to Implement Breadth First Search (BFS) Algorithm.
- **10.ii.** Write a C program to Implement Depth First Search (DFS) Algorithm.
- **10.iii.** Represent graph using adjacency matrix.
- **10.iv.** Represent graph using adjacency list.

### Experiment 11: Single Source Shortest Path
- **11.i.** Implement Dijkstra’s shortest path algorithm.

### Experiment 12: Shortest Paths
- **12.i.** Implement Bellman-Ford algorithm.
- **12.ii.** Implement Floyd-Warshall algorithm.

### Experiment 13: Minimum Spanning Tree (Prim's)
- **13.i.** Implement Prim’s Minimum Spanning Tree Algorithm.

### Experiment 14: Minimum Spanning Tree (Kruskal's)
- **14.i.** Implement Kruskal’s Minimum Spanning Tree Algorithm.

### Experiment 15: String Matching Algorithms
- **15.i.** Implement Naïve String Matching Algorithm.
- **15.ii.** Implement KMP String Matching Algorithm.
- **15.iii.** Construct LPS table for a given pattern.

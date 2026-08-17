# Contribution & Implementation Instructions

This document specifies the folder organization and file requirements for implementing solutions to the DAA lab experiments.

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

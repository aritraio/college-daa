# Experiment 1: Recursion Basics — Q4. GCD Using Recursion (Euclidean Algorithm)

## Problem Statement
Write a recursive program to find the GCD (Greatest Common Divisor) of two numbers using the Euclidean algorithm. The program reads two integers `a` and `b` and prints their GCD.

## Algorithm & Approach
- The Euclidean algorithm is based on the identity: `gcd(a, b) = gcd(b, a % b)`.
- **Base case:** when `b` becomes 0, `a` is the GCD.
- **Recursive step:** replace the pair `(a, b)` with `(b, a % b)` and repeat until the remainder is zero.
- The algorithm works for any order of inputs; if needed, a swap is handled implicitly by the recursion.

## Pseudocode
```
function gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

read a, b
print "GCD of a and b: gcd(a, b)"
```

## Complexity Analysis
- **Time Complexity:** O(log(min(a, b))) — each recursive step roughly halves the numbers.
- **Space Complexity:** O(log(min(a, b))) — recursion stack depth equals the number of steps.

## Sample Input & Output
```
Input:
48 18

Output:
GCD of 48 and 18: 6
```
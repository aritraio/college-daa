def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)


def fact(n):
    if n <= 1:
        return 1
    return n * fact(n - 1)


n = int(input())
print(f"Fibonacci series ({n} terms):", " ".join(str(fib(i)) for i in range(n)))
print(f"Factorial of {n}: {fact(n)}")
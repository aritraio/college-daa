#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

long long fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    printf("Fibonacci series (%d terms): ", n);
    for (i = 0; i < n; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", fib(i));
    }
    printf("\n");
    printf("Factorial of %d: %lld\n", n, fact(n));
    return 0;
}
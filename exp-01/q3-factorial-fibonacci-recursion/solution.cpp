#include <iostream>
using namespace std;

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
    int n;
    cin >> n;
    cout << "Fibonacci series (" << n << " terms): ";
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << fib(i);
    }
    cout << endl;
    cout << "Factorial of " << n << ": " << fact(n) << endl;
    return 0;
}
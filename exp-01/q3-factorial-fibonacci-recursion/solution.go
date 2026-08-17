package main

import "fmt"

func fib(n int) int {
	if n <= 1 {
		return n
	}
	return fib(n-1) + fib(n-2)
}

func fact(n int) int {
	if n <= 1 {
		return 1
	}
	return n * fact(n-1)
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Printf("Fibonacci series (%d terms): ", n)
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(fib(i))
	}
	fmt.Println()
	fmt.Printf("Factorial of %d: %d\n", n, fact(n))
}
package main

import "fmt"

func main() {
	var n, s int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Scan(&s)
	found := false
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if a[i]+a[j] == s {
				fmt.Printf("(%d, %d)\n", i, j)
				found = true
			}
		}
	}
	if !found {
		fmt.Println("No pairs found")
	}
}
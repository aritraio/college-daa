package main

import "fmt"

const max = 100

var s [max][max]int

func printOrder(i, j int) {
	if i == j {
		fmt.Printf("A%d", i)
		return
	}
	fmt.Print("(")
	printOrder(i, s[i][j])
	printOrder(s[i][j]+1, j)
	fmt.Print(")")
}

func main() {
	var n int
	fmt.Scan(&n)
	p := make([]int, n+1)
	for i := 0; i <= n; i++ {
		fmt.Scan(&p[i])
	}

	var m [max][max]int
	for i := 1; i <= n; i++ {
		m[i][i] = 0
	}

	for length := 2; length <= n; length++ {
		for i := 1; i <= n-length+1; i++ {
			j := i + length - 1
			m[i][j] = int(^uint(0) >> 1)
			for k := i; k < j; k++ {
				cost := m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
				if cost < m[i][j] {
					m[i][j] = cost
					s[i][j] = k
				}
			}
		}
	}

	fmt.Printf("Minimum cost: %d\n", m[1][n])
	fmt.Print("Optimal parenthesization: ")
	printOrder(1, n)
	fmt.Println()
}

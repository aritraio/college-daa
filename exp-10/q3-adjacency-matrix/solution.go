package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	mat := make([][]int, n+1)
	for i := range mat {
		mat[i] = make([]int, n+1)
	}
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		mat[u][v] = 1
		mat[v][u] = 1
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if j > 1 {
				fmt.Printf(" ")
			}
			fmt.Printf("%d", mat[i][j])
		}
		fmt.Println()
	}
}
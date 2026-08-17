package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	adj := make([][]int, n+1)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}
	for i := 1; i <= n; i++ {
		sort.Ints(adj[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Printf("%d: ", i)
		for j, v := range adj[i] {
			if j > 0 {
				fmt.Printf(" ")
			}
			fmt.Printf("%d", v)
		}
		fmt.Println()
	}
}
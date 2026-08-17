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
	var s int
	fmt.Scan(&s)

	for i := 1; i <= n; i++ {
		sort.Ints(adj[i])
	}

	visited := make([]bool, n+1)
	queue := []int{s}
	visited[s] = true
	order := []int{}
	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]
		order = append(order, u)
		for _, v := range adj[u] {
			if !visited[v] {
				visited[v] = true
				queue = append(queue, v)
			}
		}
	}
	fmt.Printf("BFS Traversal: ")
	for i, u := range order {
		if i > 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", u)
	}
	fmt.Println()
}
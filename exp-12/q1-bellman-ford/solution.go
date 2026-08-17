package main

import "fmt"

const INF = 999999

type Edge struct {
	u, v, w int
}

func main() {
	var n, m, s int
	fmt.Scan(&n, &m)

	edges := make([]Edge, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&edges[i].u, &edges[i].v, &edges[i].w)
	}
	fmt.Scan(&s)

	dist := make([]int, n+1)
	for i := 1; i <= n; i++ {
		dist[i] = INF
	}
	dist[s] = 0

	for i := 1; i <= n-1; i++ {
		changed := false
		for _, e := range edges {
			if dist[e.u] != INF && dist[e.u]+e.w < dist[e.v] {
				dist[e.v] = dist[e.u] + e.w
				changed = true
			}
		}
		if !changed {
			break
		}
	}

	for _, e := range edges {
		if dist[e.u] != INF && dist[e.u]+e.w < dist[e.v] {
			fmt.Println("Negative cycle detected")
			return
		}
	}

	fmt.Printf("Shortest distances from source %d:\n", s)
	for i := 1; i <= n; i++ {
		if dist[i] == INF {
			fmt.Printf("%d: INF\n", i)
		} else {
			fmt.Printf("%d: %d\n", i, dist[i])
		}
	}
}

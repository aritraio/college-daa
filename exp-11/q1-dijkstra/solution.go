package main

import "fmt"

const MAX = 100
const INF = 1000000000

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	var adj [MAX][MAX]int
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			adj[i][j] = INF
		}
	}

	for i := 0; i < m; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		adj[u][v] = w
	}

	var s int
	fmt.Scan(&s)

	var dist [MAX]int
	var visited [MAX]bool
	for i := 1; i <= n; i++ {
		dist[i] = INF
	}
	dist[s] = 0

	for count := 0; count < n; count++ {
		u := -1
		min := INF
		for i := 1; i <= n; i++ {
			if !visited[i] && dist[i] < min {
				min = dist[i]
				u = i
			}
		}
		if u == -1 {
			break
		}
		visited[u] = true
		for v := 1; v <= n; v++ {
			if !visited[v] && adj[u][v] < INF && dist[u]+adj[u][v] < dist[v] {
				dist[v] = dist[u] + adj[u][v]
			}
		}
	}

	for i := 1; i <= n; i++ {
		fmt.Printf("Distance from %d to %d: %d\n", s, i, dist[i])
	}
}

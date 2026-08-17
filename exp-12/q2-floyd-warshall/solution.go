package main

import "fmt"

const INF = 999999

func main() {
	var n int
	fmt.Scan(&n)

	dist := make([][]int, n)
	for i := 0; i < n; i++ {
		dist[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&dist[i][j])
		}
	}

	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if dist[i][k] != INF && dist[k][j] != INF &&
					dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if j > 0 {
				fmt.Print(" ")
			}
			if dist[i][j] == INF {
				fmt.Print("INF")
			} else {
				fmt.Print(dist[i][j])
			}
		}
		fmt.Println()
	}
}

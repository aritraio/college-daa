package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func minKey(key []int, mstSet []bool, n int) int {
	min := math.MaxInt
	minIndex := -1
	for v := 0; v < n; v++ {
		if !mstSet[v] && key[v] < min {
			min = key[v]
			minIndex = v
		}
	}
	return minIndex
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscan(in, &n, &m)

	graph := make([][]int, n)
	for i := range graph {
		graph[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		var u, v, w int
		fmt.Fscan(in, &u, &v, &w)
		graph[u-1][v-1] = w
		graph[v-1][u-1] = w
	}

	parent := make([]int, n)
	key := make([]int, n)
	mstSet := make([]bool, n)

	for i := 0; i < n; i++ {
		key[i] = math.MaxInt
		parent[i] = -1
	}

	key[0] = 0

	totalWeight := 0
	for count := 0; count < n; count++ {
		u := minKey(key, mstSet, n)
		mstSet[u] = true
		totalWeight += key[u]

		for v := 0; v < n; v++ {
			if graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v] {
				parent[v] = u
				key[v] = graph[u][v]
			}
		}
	}

	for v := 1; v < n; v++ {
		fmt.Printf("Edge %d-%d weight %d\n", parent[v]+1, v+1, key[v])
	}
	fmt.Printf("Total weight of MST: %d\n", totalWeight)
}

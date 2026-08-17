package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Edge struct {
	u, v, w int
}

func find(parent []int, x int) int {
	if parent[x] != x {
		parent[x] = find(parent, parent[x])
	}
	return parent[x]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	next := func() int {
		scanner.Scan()
		var x int
		fmt.Sscanf(scanner.Text(), "%d", &x)
		return x
	}

	n := next()
	m := next()

	edges := make([]Edge, m)
	for i := 0; i < m; i++ {
		edges[i].u = next()
		edges[i].v = next()
		edges[i].w = next()
	}

	sort.Slice(edges, func(i, j int) bool {
		return edges[i].w < edges[j].w
	})

	parent := make([]int, n+1)
	for i := 1; i <= n; i++ {
		parent[i] = i
	}

	fmt.Println("Edges in MST:")
	total, count := 0, 0
	for _, e := range edges {
		if count == n-1 {
			break
		}
		ru := find(parent, e.u)
		rv := find(parent, e.v)
		if ru != rv {
			parent[ru] = rv
			fmt.Printf("%d - %d (%d)\n", e.u, e.v, e.w)
			total += e.w
			count++
		}
	}

	fmt.Printf("Total weight of MST: %d\n", total)
}

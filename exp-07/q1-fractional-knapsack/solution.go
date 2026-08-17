package main

import (
	"fmt"
	"sort"
)

type Item struct {
	weight int
	profit int
}

func main() {
	var n int
	var w float64
	fmt.Scan(&n, &w)

	items := make([]Item, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&items[i].weight, &items[i].profit)
	}

	sort.Slice(items, func(i, j int) bool {
		return float64(items[i].profit)/float64(items[i].weight) >
			float64(items[j].profit)/float64(items[j].weight)
	})

	total := 0.0
	for _, item := range items {
		if float64(item.weight) <= w {
			total += float64(item.profit)
			w -= float64(item.weight)
		} else {
			total += float64(item.profit) * (w / float64(item.weight))
			w = 0
		}
	}

	fmt.Printf("%.2f\n", total)
}
package main

import (
	"fmt"
	"sort"
)

type Job struct {
	id       int
	deadline int
	profit   int
}

func main() {
	var n int
	fmt.Scan(&n)

	jobs := make([]Job, n)
	maxD := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&jobs[i].id, &jobs[i].deadline, &jobs[i].profit)
		if jobs[i].deadline > maxD {
			maxD = jobs[i].deadline
		}
	}

	sort.Slice(jobs, func(i, j int) bool { return jobs[i].profit > jobs[j].profit })

	slot := make([]int, maxD)
	total := 0
	for _, job := range jobs {
		for j := job.deadline - 1; j >= 0; j-- {
			if slot[j] == 0 {
				slot[j] = job.id
				total += job.profit
				break
			}
		}
	}

	fmt.Print("Selected jobs:")
	for _, s := range slot {
		if s != 0 {
			fmt.Printf(" %d", s)
		}
	}
	fmt.Printf("\nTotal profit: %d\n", total)
}
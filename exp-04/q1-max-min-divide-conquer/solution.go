package main

import "fmt"

func findMinMax(a []int, lo, hi int) (int, int) {
	if lo == hi {
		return a[lo], a[lo]
	}
	if hi == lo+1 {
		if a[lo] < a[hi] {
			return a[lo], a[hi]
		}
		return a[hi], a[lo]
	}
	mid := (lo + hi) / 2
	minL, maxL := findMinMax(a, lo, mid)
	minR, maxR := findMinMax(a, mid+1, hi)
	if minL < minR {
		minR = minL
	}
	if maxL > maxR {
		maxR = maxL
	}
	return minR, maxR
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	min, max := findMinMax(a, 0, n-1)
	fmt.Printf("Min: %d\n", min)
	fmt.Printf("Max: %d\n", max)
}
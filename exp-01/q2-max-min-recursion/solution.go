package main

import "fmt"

func findMinMax(arr []int, n int) (int, int) {
	if n == 1 {
		return arr[0], arr[0]
	}
	curMin, curMax := findMinMax(arr, n-1)
	if arr[n-1] < curMin {
		curMin = arr[n-1]
	}
	if arr[n-1] > curMax {
		curMax = arr[n-1]
	}
	return curMin, curMax
}

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	minVal, maxVal := findMinMax(arr, n)
	fmt.Printf("Min: %d\n", minVal)
	fmt.Printf("Max: %d\n", maxVal)
}
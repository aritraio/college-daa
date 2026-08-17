package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func knapsack(n, W int, wt, val []int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, W+1)
	}
	for i := 1; i <= n; i++ {
		for w := 1; w <= W; w++ {
			if wt[i-1] <= w {
				dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w])
			} else {
				dp[i][w] = dp[i-1][w]
			}
		}
	}
	return dp[n][W]
}

func main() {
	var n, W int
	fmt.Scan(&n, &W)
	wt := make([]int, n)
	val := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&wt[i], &val[i])
	}
	fmt.Println(knapsack(n, W, wt, val))
}
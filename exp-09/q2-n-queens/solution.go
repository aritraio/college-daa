package main

import "fmt"

const max = 100

var (
	n     int
	count int
	board [max]int
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func isSafe(row, col int) bool {
	for i := 0; i < row; i++ {
		if board[i] == col || abs(board[i]-col) == abs(i-row) {
			return false
		}
	}
	return true
}

func solve(row int) {
	if row == n {
		for i := 0; i < n; i++ {
			if i > 0 {
				fmt.Print(" ")
			}
			fmt.Print(board[i] + 1)
		}
		fmt.Println()
		count++
		return
	}
	for col := 0; col < n; col++ {
		if isSafe(row, col) {
			board[row] = col
			solve(row + 1)
		}
	}
}

func main() {
	fmt.Scan(&n)
	solve(0)
	fmt.Printf("Total solutions: %d\n", count)
}

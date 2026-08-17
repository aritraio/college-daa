package main

import "fmt"

func towerOfHanoi(n int, from, to, aux byte, count *int) {
	if n == 1 {
		fmt.Printf("Move disk 1 from %c to %c\n", from, to)
		*count++
		return
	}
	towerOfHanoi(n-1, from, aux, to, count)
	fmt.Printf("Move disk %d from %c to %c\n", n, from, to)
	*count++
	towerOfHanoi(n-1, aux, to, from, count)
}

func main() {
	var n int
	fmt.Scan(&n)
	count := 0
	towerOfHanoi(n, 'A', 'C', 'B', &count)
	fmt.Printf("Total moves: %d\n", count)
}
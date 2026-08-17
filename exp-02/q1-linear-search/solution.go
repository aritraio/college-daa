package main

import "fmt"

func main() {
	var n, key int
	fmt.Scan(&n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	fmt.Scan(&key)

	index := -1
	for i := 0; i < n; i++ {
		if arr[i] == key {
			index = i
			break
		}
	}

	if index == -1 {
		fmt.Println("Element not found")
	} else {
		fmt.Printf("Element found at index %d\n", index)
	}
}
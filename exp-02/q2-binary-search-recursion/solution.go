package main

import "fmt"

func binarySearch(arr []int, low, high, key int) int {
	if low > high {
		return -1
	}

	mid := low + (high-low)/2

	if arr[mid] == key {
		return mid
	} else if arr[mid] > key {
		return binarySearch(arr, low, mid-1, key)
	} else {
		return binarySearch(arr, mid+1, high, key)
	}
}

func main() {
	var n, key int
	fmt.Scan(&n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	fmt.Scan(&key)

	index := binarySearch(arr, 0, n-1, key)

	if index == -1 {
		fmt.Println("Element not found")
	} else {
		fmt.Printf("Element found at index %d\n", index)
	}
}
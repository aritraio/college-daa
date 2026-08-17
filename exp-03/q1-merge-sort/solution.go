package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func merge(arr []int, left, mid, right int) {
	n1 := mid - left + 1
	n2 := right - mid
	L := make([]int, n1)
	R := make([]int, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[left+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[mid+1+j]
	}

	i, j, k := 0, 0, left
	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}
	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}
	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}

func mergeSort(arr []int, left, right int) {
	if left < right {
		mid := left + (right-left)/2
		mergeSort(arr, left, mid)
		mergeSort(arr, mid+1, right)
		merge(arr, left, mid, right)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var nums []int
	for scanner.Scan() {
		val, _ := strconv.Atoi(scanner.Text())
		nums = append(nums, val)
	}

	n := nums[0]
	arr := make([]int, n)
	copy(arr, nums[1:1+n])

	mergeSort(arr, 0, n-1)

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Println()
}
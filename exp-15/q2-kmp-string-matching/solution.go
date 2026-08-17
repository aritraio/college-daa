package main

import (
	"bufio"
	"fmt"
	"os"
)

func computeLPS(p string) []int {
	m := len(p)
	lps := make([]int, m)
	length, i := 0, 1
	for i < m {
		if p[i] == p[length] {
			length++
			lps[i] = length
			i++
		} else if length != 0 {
			length = lps[length-1]
		} else {
			lps[i] = 0
			i++
		}
	}
	return lps
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	scanner.Scan()
	pattern := scanner.Text()
	n, m := len(text), len(pattern)
	lps := computeLPS(pattern)
	i, j := 0, 0
	found := false
	for i < n {
		if pattern[j] == text[i] {
			i++
			j++
		}
		if j == m {
			fmt.Printf("Pattern found at index %d\n", i-j)
			found = true
			j = lps[j-1]
		} else if i < n && pattern[j] != text[i] {
			if j != 0 {
				j = lps[j-1]
			} else {
				i++
			}
		}
	}
	if !found {
		fmt.Println("not found")
	}
}

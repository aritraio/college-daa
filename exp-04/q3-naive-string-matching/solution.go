package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	scanner.Scan()
	pattern := scanner.Text()
	n, m := len(text), len(pattern)
	found := false
	for i := 0; i <= n-m; i++ {
		j := 0
		for j < m && text[i+j] == pattern[j] {
			j++
		}
		if j == m {
			fmt.Printf("Pattern found at index %d\n", i)
			found = true
		}
	}
	if !found {
		fmt.Println("not found")
	}
}
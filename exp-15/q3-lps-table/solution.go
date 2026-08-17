package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	pattern := scanner.Text()
	m := len(pattern)
	lps := make([]int, m)
	length, i := 0, 1
	for i < m {
		if pattern[i] == pattern[length] {
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
	fmt.Print("LPS:")
	for i = 0; i < m; i++ {
		fmt.Printf(" %d", lps[i])
	}
	fmt.Println()
}

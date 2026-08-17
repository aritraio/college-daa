package main

import (
	"bufio"
	"fmt"
	"os"
)

func subMatrix(M [][]int, r0, c0, size int) [][]int {
	S := make([][]int, size)
	for i := 0; i < size; i++ {
		S[i] = make([]int, size)
		for j := 0; j < size; j++ {
			S[i][j] = M[r0+i][c0+j]
		}
	}
	return S
}

func putQuad(S [][]int, M [][]int, r0, c0 int) {
	size := len(S)
	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			M[r0+i][c0+j] = S[i][j]
		}
	}
}

func addMat(A, B [][]int) [][]int {
	n := len(A)
	C := make([][]int, n)
	for i := 0; i < n; i++ {
		C[i] = make([]int, n)
		for j := 0; j < n; j++ {
			C[i][j] = A[i][j] + B[i][j]
		}
	}
	return C
}

func matMul(A, B [][]int, n int) [][]int {
	if n == 1 {
		C := make([][]int, 1)
		C[0] = []int{A[0][0] * B[0][0]}
		return C
	}
	s := n / 2
	A11 := subMatrix(A, 0, 0, s)
	A12 := subMatrix(A, 0, s, s)
	A21 := subMatrix(A, s, 0, s)
	A22 := subMatrix(A, s, s, s)
	B11 := subMatrix(B, 0, 0, s)
	B12 := subMatrix(B, 0, s, s)
	B21 := subMatrix(B, s, 0, s)
	B22 := subMatrix(B, s, s, s)

	M1 := matMul(A11, B11, s)
	M2 := matMul(A12, B21, s)
	M3 := matMul(A11, B12, s)
	M4 := matMul(A12, B22, s)
	M5 := matMul(A21, B11, s)
	M6 := matMul(A22, B21, s)
	M7 := matMul(A21, B12, s)
	M8 := matMul(A22, B22, s)

	C11 := addMat(M1, M2)
	C12 := addMat(M3, M4)
	C21 := addMat(M5, M6)
	C22 := addMat(M7, M8)

	C := make([][]int, n)
	for i := 0; i < n; i++ {
		C[i] = make([]int, n)
	}
	putQuad(C11, C, 0, 0)
	putQuad(C12, C, 0, s)
	putQuad(C21, C, s, 0)
	putQuad(C22, C, s, s)
	return C
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	readInt := func() int {
		scanner.Scan()
		var v int
		fmt.Sscanf(scanner.Text(), "%d", &v)
		return v
	}

	n := readInt()
	A := make([][]int, n)
	B := make([][]int, n)
	for i := 0; i < n; i++ {
		A[i] = make([]int, n)
		for j := 0; j < n; j++ {
			A[i][j] = readInt()
		}
	}
	for i := 0; i < n; i++ {
		B[i] = make([]int, n)
		for j := 0; j < n; j++ {
			B[i][j] = readInt()
		}
	}

	C := matMul(A, B, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if j > 0 {
				fmt.Print(" ")
			}
			fmt.Printf("%d", C[i][j])
		}
		fmt.Println()
	}
}

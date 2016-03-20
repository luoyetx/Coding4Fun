package main

import "fmt"

func getRow(rowIndex int) []int {
	n := rowIndex
	res := make([]int, n+1)
	res[0] = 1
	for i := 0; i < n; i++ {
		res[i+1] = res[i] * (n - i) / (i + 1)
	}
	return res
}

func main() {
	row := getRow(5)
	fmt.Println(row)
}

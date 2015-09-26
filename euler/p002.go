package main

import "fmt"

func fib(fibs chan int) {
	x := 1
	y := 2
	z := 3
	fibs <- 2
	for z <= 4000000 {
		if z%2 == 0 {
			fibs <- z
		}
		x = y
		y = z
		z = x + y
	}
	close(fibs)
}

func main() {
	fibs := make(chan int)
	go fib(fibs)
	sum := 0
	for e := range fibs {
		sum += e
	}
	fmt.Println(sum)
}

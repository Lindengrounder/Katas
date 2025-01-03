// код на Go (протестирован на JDoodle.com)
//
// Разбиение чисел на множетели.
//
// дата теста: 03.01.2025

package main

import "fmt"

func main() {
	fmt.Print("Enter an integer number: ")
	var number int
	fmt.Scan(&number)
	
	i := 2
	for i <= number {
		if number % i == 0 {
			fmt.Print(i)
			number = number / i
			if number > 1 {
				fmt.Print("*")
			}
		} else {
			i++
		}
	}
	fmt.Println()
	fmt.Println("max =", i)
}

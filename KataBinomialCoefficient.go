//добавлен запрос у пользователя степени бинома
//дата теста на jdoodle.com - 20.01.2025

package main

import (
	"fmt"
)

func main() {
	fmt.Println("Введите степень бинома:")
	var n int
	fmt.Scan(&n)
	fmt.Println("Биномиальные коэффициенты:")
	for k := 0; k <= n; k++ {
		fmt.Printf("C %d %d = %d\n", k, n-k, binomialCoefficient(n, k))
	}
}

func binomialCoefficient(n, k int) int {
	if k > n-k {
		k = n - k
	}
	result := 1
	for i := 1; i <= k; i++ {
		result *= (n-k+i)
		result /= i
	}
	return result
}

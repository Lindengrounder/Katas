package main

import (
	"fmt"
)

func main() {
	n := 5 // Степень бинома
	fmt.Println("Биномиальные коэффициенты:")
	for k := 0; k <= n; k++ {
		fmt.Printf("C%d%d = %d\n", k, n-k, binomialCoefficient(n, k))
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

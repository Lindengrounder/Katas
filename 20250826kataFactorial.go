//проведено тестирование на jdoodle
package main

import (
	"fmt"
	"math/big"
)

// Factorial вычисляет факториал заданного числа.
func Factorial(n int) *big.Int {
	if n == 0 {
		return big.NewInt(1)
	}

	result := big.NewInt(1)
	for i := 2; i <= n; i++ {
		result.Mul(result, big.NewInt(int64(i)))
	}
	return result
}

func main() {
	var n int
	fmt.Print("Введите число для вычисления факториала: ")
	fmt.Scanln(&n)

	if n < 0 {
		fmt.Println("Факториал отрицательного числа не определен.")
		return
	}

	result := Factorial(n)
	fmt.Printf("Факториал числа %d равен %s\n", n, result.String())
}

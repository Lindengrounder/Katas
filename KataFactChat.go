//03.02.2025 Open.AI Chat GPT

package main

import (
	"fmt"
)

// Функция для вычисления факториала
func factorial(n int) int {
	if n == 0 || n == 1 {
		return 1
	}
	return n * factorial(n-1)
}

func main() {
	for {
		fmt.Println("Меню:")
		fmt.Println("1. Вычислить факториал")
		fmt.Println("2. Выйти")
		fmt.Print("Выберите действие: ")

		var choice int
		fmt.Scan(&choice)

		switch choice {
		case 1:
			fmt.Print("Введите число: ")
			var num int
			fmt.Scan(&num)

			if num < 0 {
				fmt.Println("Факториал определён только для неотрицательных чисел!")
			} else {
				fmt.Printf("Факториал %d = %d\n", num, factorial(num))
			}
		case 2:
			fmt.Println("Выход из программы.")
			return
		default:
			fmt.Println("Некорректный ввод, попробуйте снова.")
		}
	}
}

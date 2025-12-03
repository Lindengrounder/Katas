//03.02.2025 DeepSeek

package main

import (
	"fmt"
	"os"
)

func main() {
	for {
		printMenu()
		choice := readChoice()
		
		switch choice {
		case 1:
			calculateFactorial()
		case 2:
			fmt.Println("До свидания!")
			os.Exit(0)
		default:
			fmt.Println("Неверный выбор, попробуйте снова")
		}
	}
}

func printMenu() {
	fmt.Println("\nМеню:")
	fmt.Println("1. Вычислить факториал")
	fmt.Println("2. Выход")
	fmt.Print("Выберите опцию: ")
}

func readChoice() int {
	var choice int
	_, err := fmt.Scanln(&choice)
	if err != nil {
		return -1
	}
	return choice
}

func calculateFactorial() {
	var n int
	fmt.Print("Введите неотрицательное целое число: ")
	_, err := fmt.Scanln(&n)
	
	if err != nil || n < 0 {
		fmt.Println("Ошибка ввода! Пожалуйста, введите корректное число")
		fmt.Scanln() // Очистка буфера
		return
	}

	if n > 20 {
		fmt.Println("Предупреждение: результат может быть некорректным из-за переполнения")
	}

	result := factorial(n)
	fmt.Printf("Факториал %d = %d\n", n, result)
}

func factorial(n int) uint64 {
	if n == 0 {
		return 1
	}
	
	var result uint64 = 1
	for i := 1; i <= n; i++ {
		result *= uint64(i)
	}
	return result
}

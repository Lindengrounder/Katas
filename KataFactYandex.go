//03.02.2025 Яндекс, Алиса
//Привет - можешь написать простой код на Go, реализующий вычисление факториала (с выводом и меню в консоли)
package main

import (
	"fmt"
	"os"
)

func main() {
	// Вывод меню
	fmt.Println("Выберите действие:")
	fmt.Println("1. Вычисление факториала")
	fmt.Println("2. Выход")

	// Обработка выбора пользователя
	var choice int
	fmt.Println("Ваш выбор: ")
	fmt.Scan(&choice)
	switch choice {
	case 1:
		// Ввод числа от пользователя
		fmt.Println("Введите число:")
		var number int
		fmt.Scan(&number)
		fmt.Println("Факториал числа", number, "равен", factorial(number))
	case 2:
		fmt.Println("Программа завершена.")
		os.Exit(0)
		break
	default:
		fmt.Println("Некорректный выбор. Попробуйте еще раз.")
	}
}

func factorial(n int) int {
	fact := 1
	for i := 1; i <= n; i++ {
		fact *= i
	}
	return fact
}

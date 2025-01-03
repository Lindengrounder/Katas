// код на Go (протестирован на JDoodle.com)
//
// Разбиение чисел на множетели. Оптимизированная (?) версия
//
// дата теста: 03.01.2025

package main

import "fmt"

func main() {
	fmt.Print("Enter an integer number: ")
	var number int
	fmt.Scan(&number)

	// Массив для хранения простых чисел до n
	primes := sieveOfEratosthenes(number)

	// Инициализация первого простого числа
	i := primes[0]

	// Разложение числа на множители
	fmt.Print(i, "*")
	number /= i
	for i = primes[1]; i < len(primes) && number > 1; i++ {
		if number%primes[i] == 0 {
			fmt.Print("*", primes[i], "*")
			number /= primes[i]
		}
	}

	// Вывод оставшегося множителя
	if number > 1 {
		fmt.Print("*", number)
	}
	fmt.Println()
}

// Функция для генерации массива простых чисел до n
func sieveOfEratosthenes(n int) []int {
	// Инициализация массива для хранения простых чисел
	isPrime := make([]bool, n+1)
	for i := 0; i <= n; i++ {
		isPrime[i] = true
	}

	// Инициализация простых чисел
	primes := []int{2}

	// Проходим по всем числам от 2 до корня из n
	for i := 2; i*i <= n; i++ {
		if isPrime[i] {
			// Заполняем массив составными числами, кратными i
			for j := i * i; j <= n; j += i {
				isPrime[j] = false
			}
		}
	}

	// Собираем оставшиеся простые числа
	for i := 2; i <= n; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}

	return primes
}

//sieveOfEratosthenes: Функция генерирует массив всех простых чисел до заданного n. Это позволяет быстро находить множители числа без необходимости каждый раз проверять делимость на все числа до n.
//Вместо перебора всех чисел до number, используются найденные простые числа, что значительно ускоряет процесс разложения на множители.
//Программа выводит найденные множители, разделяя их знаком *, что упрощает чтение и восприятие результата.

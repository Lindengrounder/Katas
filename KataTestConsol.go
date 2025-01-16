/*
Тестовая программа для вывода сообщений на экран с поддержкой многопоточности
Дата теста 16.01.2025
UPD:
Функция printGreeting: Выводит приветственное сообщение на экран.
Функция displayASCIITable: Выводит таблицу ASCII (символы с кодами от 32 до 126).
Функция displayMenu: Отображает меню с доступными опциями.
Меню в main:

    Пользователь выбирает опцию, вводя соответствующую букву.
    Если ввод некорректен, программа сообщает об ошибке и предлагает попробовать снова.
    Для выхода из программы предусмотрен выбор e.
UPD 2:
    Функция testConcurrency: Эта функция запускает две горутины, каждая из которых выполняет свою задачу с небольшой задержкой. Горутины записывают сообщения в канал по завершению своих задач.
    Использование канала (resultChannel): Канал используется для получения сообщений от горутин, что позволяет синхронизировать их выполнение и выводить результаты в нужном порядке.
    Добавление опции "f" в меню: Это позволяет пользователю запускать тест многопоточности.

Как это работает:

    При выборе пользователем опции "f", программа запускает две горутины.
        Первая горутина завершает выполнение через 2 секунды.
        Вторая горутина завершает выполнение через 1 секунду.
    После завершения обеих горутин программа выводит сообщения из канала в порядке их завершения.
    Это демонстрирует возможность параллельного выполнения задач в Go.
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"time"
)

// Функция для вычисления суммы двух чисел
func printSum() {
	x := 10
	y := 25
	z := x + y
	fmt.Printf("The sum of x (%d) and y (%d) is: %d\n", x, y, z)
}

// Функция для симуляции работы с памятью
func displayMessage() {
	fmt.Println("Displaying a message to simulate low-level memory interaction...")

	// Симуляция записи в память
	simulatedMemory := []byte{'H', 0x07, 'i', 0x07}
	fmt.Printf("Simulated memory contains: %c%c\n", simulatedMemory[0], simulatedMemory[2])
}

// Новая функция для вывода приветственного сообщения
func printGreeting() {
	fmt.Println("Hello! This is a test program for console functionality.")
}

// Новая функция для вывода таблицы ASCII
func displayASCIITable() {
	fmt.Println("ASCII Table:")
	for i := 32; i < 127; i++ {
		fmt.Printf("%3d: %c\t", i, i)
		if (i-31)%8 == 0 {
			fmt.Println()
		}
	}
	fmt.Println()
}

// Меню программы
func displayMenu() {
	fmt.Println("\n--- Main Menu ---")
	fmt.Println("a - Compute the sum of x and y")
	fmt.Println("b - Simulate low-level memory interaction")
	fmt.Println("c - Print a greeting message")
	fmt.Println("d - Display the ASCII table")
	fmt.Println("f - Concurrency test")
	
	fmt.Println("e - Exit the program")
	
	fmt.Print("Choose an option: ")
}

// Функция для тестирования многопоточности
func testConcurrency() {
	// Канал для передачи результатов
	resultChannel := make(chan string)

	// Функция, которая выполняется в горутине
	go func() {
		time.Sleep(2 * time.Second) // Имитация задержки
		resultChannel <- "Goroutine 1 has completed its task!"
	}()

	// Еще одна горутина
	go func() {
		time.Sleep(1 * time.Second) // Имитация задержки
		resultChannel <- "Goroutine 2 has completed its task!"
	}()

	// Ожидаем результаты от обеих горутин
	result1 := <-resultChannel
	result2 := <-resultChannel

	// Выводим полученные результаты
	fmt.Println(result1)
	fmt.Println(result2)
}

// Главная функция программы
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Welcome to the program with a menu system!")

	// Бесконечный цикл для отображения меню
	for {
		displayMenu()
		choice, _ := reader.ReadString('\n')
		choice = strings.TrimSpace(choice) // Удаляем лишние пробелы и символы новой строки

		// Выполнение действий на основе выбора
		switch choice {
		case "a":
			printSum()
		case "b":
			displayMessage()
		case "c":
			printGreeting()
		case "d":
			displayASCIITable()
		case "e":
			fmt.Println("Exiting the program. Goodbye!")
			return // Завершение программы
		case "f":
			// Запуск теста многопоточности
			fmt.Println("Starting concurrency test...")
			testConcurrency()
		default:
			fmt.Println("Invalid choice. Please try again.")
		}
	}
}

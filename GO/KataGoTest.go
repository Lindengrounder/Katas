// Учвебный код, который демонстрирует рабут Map в golang
package main

import "fmt"

var groupCity = map[int][]string{
	10:   {"Магас", "Салехард", "Город1"},
	100:  {"Тверь", "Тула", "Калуга"},
	1000: {"Москва", "Санкт-Петербург", "Новосибирск"},
}

var cityPopulation = map[string]int{
	"Магас":           10,
	"Салехард":        20,
	"Тверь":           450,
	"Тула":            480,
	"Калуга":          325,
	"Москва":          12000,
	"Санкт-Петербург": 5300,
	"Новосибирск":     1600,
	"Город1":          15,
}

func main() {
	for key := range cityPopulation {
		flag := false
		for _, value := range groupCity[100] {
			if key == value {
				flag = true
				break
			}
		}
		if !flag {
			delete(cityPopulation, key)
		}
		// Выводим результат в процессе фильтрации
		fmt.Println("\nПосле фильтрации (города с населением 100-999 тыс. человек):")
		for city, population := range cityPopulation {
			fmt.Printf("Город: %s, Население: %d тыс. человек\n", city, population)
		}

		// Выводим статистику
		fmt.Printf("\nИтого осталось городов: %d\n", len(cityPopulation))
	}
}

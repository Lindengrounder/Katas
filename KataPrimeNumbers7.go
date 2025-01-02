/* 
Код на Go (протестирован на JDoodle.com)

Нахождение всех простых чисел до заданного лимита

Дата теста: 02.01.2025
*/
package main

import "fmt"

func main() {
    fmt.Print("Enter the limit number: ")
    var number int
    fmt.Scan(&number)
    
    for j := 2; j <= number; j++ {
        var isPrime bool
        for i := 2; i * i <= j && !isPrime; i++ {
            if j % i == 0 {
                isPrime = true
                break
            }
        }
        if !isPrime {
            fmt.Println(j)
        }
    }
}

/* В языке Go необходимо использовать fmt.Println вместо printf и fmt.Scan(&number) вместо scanf.
В Go переменные должны быть объявлены до использования. В этом случае number и isPrime должны быть объявлены с указанием типа.
В Go цикл for и условные операторы имеют специфический синтаксис.*/

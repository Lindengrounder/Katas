/* 
код на C++ (протестирован на JDoodle.com)

Нахождение всех простых чисел до заданного лимита

дата теста: 31.12.2024
*/
#include <iostream>

int main() {
    int limit;
    std::cout << "Enter the limit number: ";
    std::cin >> limit;

    for (int j = 2; j <= limit; j++) {  // Начинаем с 2, а не с 1
        bool isPrime = true;
        for (int i = 2; i * i <= j && isPrime; i++) {
            if (j % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << j << std::endl;
        }
    }

    return 0;
}

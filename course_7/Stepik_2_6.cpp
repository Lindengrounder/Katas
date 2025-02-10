#include <iostream>

// Функция для вычисления длины C-style строки
size_t strlen_custom(const char* str) {
    size_t length = 0;
    
    // Проходим по строке, пока не встретим нулевой символ
    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}

int main() {
    const char* example = "Hello World!";
    std::cout << "Длина строки: " << strlen_custom(example) << std::endl;
    return 0;
}

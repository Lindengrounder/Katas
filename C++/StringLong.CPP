#include <iostream>

// Алгоритм:
// Инициализируем счётчик length нулём
// Проходим по строке, пока не встретим нулевой символ '\0'
// Увеличиваем счётчик для каждого ненулевого символа

size_t strlen(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

// Вариант с указателями
size_t strlen_ptr(const char* str) {
    const char* s = str;
    while (*s) ++s;
    return s - str;
}

// Рекурсивный вариант (менее эффективен по "О")
size_t strlen_recursive(const char* str) {
    return (*str == '\0') ? 0 : 1 + strlen_recursive(str + 1);
}

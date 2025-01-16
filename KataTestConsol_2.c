/* низкоуровневый тест консоли */
/* дата теста 16.01.2025*/
#include <stdio.h>

void printSum();
void displayMessage();

int main() {
    // Вызов функции для вычисления и вывода суммы
    printSum();

    // Вызов функции для демонстрации работы с видеопамятью (если применимо)
    displayMessage();

    return 0;
}

// Функция для вычисления и вывода суммы двух чисел
void printSum() {
    int x = 10;
    int y = 25;
    int z = x + y;
    printf("Sum of x + y = %d\n", z);
}

// Функция для отображения сообщения с использованием видеопамяти
void displayMessage() {
    // Это работает только на некоторых низкоуровневых системах (например, DOS)
    char *video_memory = (char *)0xb8000;
    video_memory[0] = 'H';
    video_memory[1] = 0x07;  // Белый цвет на черном фоне
    video_memory[2] = 'i';
    video_memory[3] = 0x07;  // Белый цвет на черном фоне
    printf("Message written to video memory (if applicable).\n");
}

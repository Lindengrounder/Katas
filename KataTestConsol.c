/*Тестовая программа для вывода сообщений на экран
Дата теста 16.01.2025*/

#include <stdio.h>

void printSum() {
    int x = 10;
    int y = 25;
    int z = x + y;
    printf("The sum of x (%d) and y (%d) is: %d\n", x, y, z);
}

void displayMessage() {
    printf("Displaying a message to simulate low-level memory interaction...\n");

    // Симуляция записи в память, чтобы проиллюстрировать функционал
    char simulated_memory[4];
    simulated_memory[0] = 'H';
    simulated_memory[1] = 0x07;
    simulated_memory[2] = 'i';
    simulated_memory[3] = 0x07;

    printf("Simulated memory contains: %c%c\n", simulated_memory[0], simulated_memory[2]);
}

int main() {
    printf("Welcome to the program!\n");
    
    // Вычисление суммы
    printSum();

    // Симуляция вывода сообщения
    displayMessage();

    printf("Program has finished executing.\n");
    return 0;
}

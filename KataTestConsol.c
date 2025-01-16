/* 
Тестовая программа для вывода сообщений на экран
Дата теста 16.01.2025
UPD:
Функция printGreeting: Выводит приветственное сообщение на экран.
Функция displayASCIITable: Выводит таблицу ASCII (символы с кодами от 32 до 126).
Функция displayMenu: Отображает меню с доступными опциями.
Меню в main:

    Пользователь выбирает опцию, вводя соответствующую букву.
    Если ввод некорректен, программа сообщает об ошибке и предлагает попробовать снова.
    Для выхода из программы предусмотрен выбор e.
*/

#include <stdio.h>

// Функция для вычисления суммы двух чисел
void printSum() {
    int x = 10;
    int y = 25;
    int z = x + y;
    printf("The sum of x (%d) and y (%d) is: %d\n", x, y, z);
}

// Функция для симуляции работы с памятью
void displayMessage() {
    printf("Displaying a message to simulate low-level memory interaction...\n");

    // Симуляция записи в память
    char simulated_memory[4];
    simulated_memory[0] = 'H';
    simulated_memory[1] = 0x07;
    simulated_memory[2] = 'i';
    simulated_memory[3] = 0x07;

    printf("Simulated memory contains: %c%c\n", simulated_memory[0], simulated_memory[2]);
}

// Новая функция для вывода приветственного сообщения
void printGreeting() {
    printf("Hello! This is a test program for console functionality.\n");
}

// Новая функция для вывода таблицы ASCII
void displayASCIITable() {
    printf("ASCII Table:\n");
    for (int i = 32; i < 127; i++) {
        printf("%3d: %c\t", i, i);
        if ((i - 31) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Меню программы
void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("a - Compute the sum of x and y\n");
    printf("b - Simulate low-level memory interaction\n");
    printf("c - Print a greeting message\n");
    printf("d - Display the ASCII table\n");
    printf("e - Exit the program\n");
    printf("Choose an option: ");
}

// Главная функция программы
int main() {
    char choice;

    printf("Welcome to the program with a menu system!\n");

    // Бесконечный цикл для отображения меню
    while (1) {
        displayMenu();
        scanf(" %c", &choice); // Чтение выбора пользователя

        // Выполнение действий на основе выбора
        switch (choice) {
            case 'a':
                printSum();
                break;
            case 'b':
                displayMessage();
                break;
            case 'c':
                printGreeting();
                break;
            case 'd':
                displayASCIITable();
                break;
            case 'e':
                printf("Exiting the program. Goodbye!\n");
                return 0; // Завершение программы
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

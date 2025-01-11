/* протестировал в Code::Bloks 20.03
компилятор gcc (GCC) 14.2.0
10.01.2025 - дата теста: Есть ошибка, генерит только из символов пароль*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Набор символов для генерации пароля
char symbols[] = "@!$+=-_?*()";

// Функция для генерации случайного пароля
char *generate_password(int length) {
 char *password = malloc(length + 1);
 if (password == NULL) {
 perror("Memory allocation failed");
 exit(EXIT_FAILURE);
 }

 // Инициализация генератора случайных чисел
 srand(time(NULL));

 // Генерация случайного пароля
 for (int i = 0; i < length; i++) {
 password[i] = symbols[rand() % (sizeof(symbols) - 1)]; // Случайный символ из набора
 }
 password[length] = '\0'; // Завершающий символ конца строки

 return password;
}

int main() {
 // Длина пароля
 int length = 12;

 // Генерация пароля
 char *password = generate_password(length);

 // Вывод пароля
 printf("Generated password: %s\n", password);

 // Освобождение памяти
 free(password);

 return 0;
}

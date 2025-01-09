// KataTetris12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// дата теста: 07.01.2025 - второй блин комом 
//             09.01.2025 - Тестирование в Visual Studio - разобрался со sleep, но пока не получается чистить экран

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "windows.h" //для windows
//#include <unistd.h> // для linux
//#include "conio.h"

#define N 20

// Матрица для игрового поля
char board[N][N];

// Определение фигур Тетриса
typedef struct {
    int x, y;
    char shape;
} tetromino;

// Фигуры Тетриса
tetromino shapes[7] = {
    {'I', 0, 0},
    {'J', 0, 0},
    {'L', 0, 0},
    {'O', 0, 0},
    {'S', 0, 0},
    {'T', 0, 0},
    {'Z', 0, 0}
};

// Функция для генерации новой случайной фигуры
void newPiece() {
    int i, j;
    for (i = 0; i < 7; ++i) {
        shapes[i].x = 0;
        shapes[i].y = 0;
        shapes[i].shape = ' ';
    }
    for (i = 0; i < 4; ++i) {
        j = rand() % 7;
        shapes[j].x = 1;
        shapes[j].y = i + 1;
        //shapes[j].shape = tetromino shape[j]; // Исправлено
    }
}

// Функция для очистки экрана
void clearScreen() {
    // Можно использовать библиотеку curses или написать свою функцию для очистки экрана
    //fprintf(stderr, "\0332J\0331;1H"); // ANSI escape sequences for clearing screen
    // В Linux: system("clear");
    system("cls");
    //clrscr();
    //system("clear"); // clear output screen
    //char a[80];
    //printf("\033[2J"); /* Clear the entire screen. */
    //printf("\033[0;0f"); /* Move cursor to the top left hand corner */
    //fflush(stdin);
}

// Функция для рисования игрового поля
void drawField() {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (i < 4 || j < 4) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Функция для рисования фигуры
void drawTetromino(tetromino t) {
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (board[t.y + i][t.x + j] == ' ') {
                board[t.y + i][t.x + j] = t.shape;
            }
        }
    }
}

// Основная игровая логика
void gameLogic() {
    int i, j, k, move;
    tetromino t;

    // Проверка на заполнение строки
    for (i = 0; i < N; ++i) {
        if (board[3][i] == ' ') continue; // Исправлено

        // Проверка на наличие фигуры
        for (j = 0; j < 4; ++j) {
            if (board[3][i] == shapes[j].shape) {
                t = shapes[j];
                break;
            }
        }

        // Проверка на совпадение
        for (k = 0; k < 4; ++k) {
            if (board[t.y + k][i] != ' ') {
                break;
            }
        }

        // Если совпадение, сдвиг фигуры вниз
        if (k == 4) {
            for (j = 0; j < 4; ++j) {
                board[3 + j][i] = ' ';
            }
        }
    }
}


// Основная функция игры
int main() {
    srand(time(NULL));

    // Инициализация игрового поля
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = ' ';
        }
    }

    clearScreen();
    drawField();

    while (1) {
        gameLogic();
        drawField();
              //  if (kbhit()) 
        {
            switch (1 /*getch()*/) {
            case 'q':
                exit(0);
                break;
            case 'r':
                newPiece();
                break;
            }
        }

        // Задержка для анимации
       Sleep(2000);
    }

    //   return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

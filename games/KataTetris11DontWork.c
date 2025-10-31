// Первый блин комом) код на C (протестирован на JDoodle.com)
//
// Игра тетрис (не работает пока)
//
// дата теста: 06.01.2025
// дата теста: 08.01.2025 - снова на JDoodle, попробовал разные функции очистки экрана - не ок
// зато разобрался как рабоатет функция генерации игрового поля

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>

#define N 20

// Определение фигур Тетриса
typedef struct {
    int x, y;
    char shape;
} tetromino;

// Фигуры Тетриса
tetromino shapes[7] = {
    {0, 0, 'I'},
    {0, 0, 'J'},
    {0, 0, 'L'},
    {0, 0, 'O'},
    {0, 0, 'S'},
    {0, 0, 'T'},
    {0, 0, 'Z'}
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
//        shapes[j].shape = tetromino[j].shape;
    }
}

// Функция для очистки экрана
void clearScreen() {
    system("cls");
     system("clear"); // clear output screen
    char a[80];
printf("\033[2J"); /* Clear the entire screen. */
printf("\033[0;0f"); /* Move cursor to the top left hand corner */
fflush(stdin);
}

// Функция для рисования игрового поля
void drawField() {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (i < 4 || j < 4) {
                printf("%%");
            } else {
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
//            if (board[t.y + i][t.x + j] == ' ') 
            {
 //               board[t.y + i][t.x + j] = t.shape;
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
 //       if (/*board[3][i] == ' '*/) continue;
        
        // Проверка на наличие фигуры
        for (j = 0; j < 4; ++j) {
  //          if (board[3][i] == shapes[j].shape) 
            {
                t = shapes[j];
                break;
            }
        }
        
        // Проверка на совпадение
        for (k = 0; k < 4; ++k) {
//            if (board[t.y + k][i] != ' ') 
            {
                break;
            }
        }
        
        // Если совпадение, сдвиг фигуры вниз
        if (k == 4) {
            for (j = 0; j < 4; ++j) {
   //             board[3 + j][i] = ' ';
            }
        }
    }
}

// Основная функция игры
void main() {
    srand(time(NULL));
    clearScreen();
   // drawField();
    
    /*while (1)*/ {
        gameLogic();
        drawField();
        
//        if (kbhit()) 
{
            switch ( 1 /*getch()*/ ) {
                case 'q':
                    exit(0);
                    break;
                case 'r':
                    newPiece();
                    break;
            }
                clearScreen();
        }
        
        // Задержка для анимации
     //   sleep(1);
    }
    
 //   return 0;
}

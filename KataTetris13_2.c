#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h> // для Windows

#define N 20

char board[N][N];

typedef struct {
    int x, y;
    char shape;
} tetromino;

tetromino shapes[7] = {
    {0, 0, 'I'},
    {0, 0, 'J'},
    {0, 0, 'L'},
    {0, 0, 'O'},
    {0, 0, 'S'},
    {0, 0, 'T'},
    {0, 0, 'Z'}
};

void clearScreen() {
    system("cls");
}

void drawField() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void drawTetromino(tetromino t) {
    if (t.y < N && t.x < N) {
        board[t.y][t.x] = t.shape;
    }
}

void resetBoard() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 7; ++i) {
        resetBoard();
        shapes[i].x = N / 2;
        shapes[i].y = N / 2;
        drawTetromino(shapes[i]);
        clearScreen();
        drawField();
       // Sleep(1000); // Задержка для просмотра фигуры
    }

    return 0;
}

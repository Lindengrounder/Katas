/* 
KataTetris13.c

Эксперементирую с функциями для Тетриса

10.01.2025 - Протестировано на JDoodle.com
*/
#include<stdio.h>

void risPole();

int N = 24;
struct tetromino 
{
    int x, y;
    char shape;
} ;

//void risTetromino(tetromino t);

int main()
{
    struct tetromino tom = { 12, 120, 120 }; // char 120 это "x"
    int x=10;
    int y=25;
    int z=x+y;
    printf("Sum of x+y = %i \n", z);
    risPole();
    printf("x:%d \t y: %d Shape: %c", tom.x, tom.y, tom.shape);
    //risTetromino (t);
}

void risPole() 
{
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

/*void risTetromino(tetromino t) 
{
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (board[t.y + i][t.x + j] == ' ') {
                board[t.y + i][t.x + j] = t.shape;
            }
        }
    }
}*/

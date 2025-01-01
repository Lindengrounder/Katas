/* 
Код на C (протестирован на JDoodle.com)

Нахождение всех простых чисел до заданного лимита

Дата теста: 01.01.2025
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    printf ("Enter the limit number: ");
    int number = 0;
    scanf("%d", &number);
    for (int j = 2; j <= number; j++)
    {
        int isPrime = 1;
        for (int i = 2; i * i <= j && isPrime; i++)
        {
            if (j % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) 
        {
            printf("\n %i", j);
        }
    }
}

// код на C (протестирован на JDoodle.com)
//
// Разбиение чисел на множетели.
//
// дата теста: 29.12.2024
//

#include<stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter an integer number: ");
    int number, i = 2;
    scanf("%d", &number);
    while (i <= number)
    {
        if (number % i == 0)
            {
                printf("%d",i);
                number = number / i;
                if (number > 1)
                {
                    printf("*");
                }
            }
            else
            {
                i++;
            }
    }
    printf("\n max = %i", i);
    return 0;
}

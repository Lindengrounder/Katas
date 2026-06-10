#include <stdio.h>
#include <time.h>

// Функция возвращает номер дня в году (1–366)
int get_day_of_year(int *year, int *month, int *day) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    *year = tm_info->tm_year + 1900;
    *month = tm_info->tm_mon + 1;
    *day = tm_info->tm_mday;
    return tm_info->tm_yday + 1; // tm_yday начинается с 0
}

int main() {
    int year, month, day;
    int day_of_year = get_day_of_year(&year, &month, &day);
    
    // Правильное склонение для русского языка
    const char *day_suffix;
    if (day_of_year % 10 == 1 && day_of_year % 100 != 11)
        day_suffix = "й";
    else if (day_of_year % 10 >= 2 && day_of_year % 10 <= 4 &&
             (day_of_year % 100 < 10 || day_of_year % 100 >= 20))
        day_suffix = "й";
    else
        day_suffix = "й"; // в русском для порядковых числительных чаще всего "й" или "ый", но для номера дня года проще "й"
    // Более точно: "1-й", "2-й", "3-й", "4-й", "5-й"... все на "-й"
    // Поэтому оставим один вариант
    
    printf("Сегодня %d-%02d-%02d, %d-й день %d года.\n",
           year, month, day, day_of_year, year);
    
    return 0;
}
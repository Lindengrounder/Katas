#include <stdio.h>
#include <time.h>

// Function returns day of year (1–366)
int get_day_of_year(int *year, int *month, int *day) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    *year = tm_info->tm_year + 1900;
    *month = tm_info->tm_mon + 1;
    *day = tm_info->tm_mday;
    return tm_info->tm_yday + 1; // tm_yday starts from 0
}

int main() {
    int year, month, day;
    int day_of_year = get_day_of_year(&year, &month, &day);
    
    // Determine correct ordinal suffix (st, nd, rd, th)
    const char *suffix;
    if (day_of_year % 10 == 1 && day_of_year % 100 != 11)
        suffix = "st";
    else if (day_of_year % 10 == 2 && day_of_year % 100 != 12)
        suffix = "nd";
    else if (day_of_year % 10 == 3 && day_of_year % 100 != 13)
        suffix = "rd";
    else
        suffix = "th";
    
    printf("Today is %d-%02d-%02d, the %d%s day of the year %d.\n",
           year, month, day, day_of_year, suffix, year);
    
    printf("\nPress Enter to exit...");
    getchar(); // Wait for user to press Enter
    
    return 0;
}
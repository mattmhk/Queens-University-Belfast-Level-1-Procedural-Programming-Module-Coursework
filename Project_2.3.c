#include<stdio.h>

int main()
{
    char day1,day2,month1,month2,year1,year2,year3,year4;
    printf("Enter a date (DD/MM/YYYY): ");
    scanf(" %c%c/%c%c/%c%c%c%c", &day1, &day2, &month1, &month2, &year1, &year2, &year3, &year4);
    printf("You entered the date: %c%c%c%c/%c%c/%c%c\n", year1, year2, year3, year4, month1, month2, day1, day2);
}
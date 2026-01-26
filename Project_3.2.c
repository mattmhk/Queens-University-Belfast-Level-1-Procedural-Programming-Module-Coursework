#include<stdio.h>

int main()
{
    char letter1,letter2,letter3;
    printf("Enter a day (Mon/Tue/Wed/Thu/Fri/Sat/Sun): ");
    scanf(" %c %c %c", &letter1, &letter2, &letter3);
    if((letter1=="M" || letter1=="m") && (letter2=="o" || letter2=="O") && (letter3=="n" || letter3=="N"))
    {
        printf("The day number is 1.\n");
    }
    else if((letter1=="T" || letter1=="t") && (letter2=="u" || letter2=="U") && (letter3=="e" || letter3=="E"))
    {
        printf("The day number is 2.\n");
    }
    else if((letter1=="W" || letter1=="w") && (letter2=="e" || letter2=="E") && (letter3=="d" || letter3=="D"))
    {
        printf("The day number is 3.\n");
    }
    else if((letter1=="T" || letter1=="t") && (letter2=="h" || letter2=="H") && (letter3=="u" || letter3=="U"))
    {
        printf("The day number is 4.\n");
    }
    else if((letter1=="F" || letter1=="f") && (letter2=="r" || letter2=="R") && (letter3=="i" || letter3=="I"))
    {
        printf("The day number is 5.\n");
    }
    else if((letter1=="S" || letter1=="s") && (letter2=="a" || letter2=="A") && (letter3=="t" || letter3=="T"))
    {
        printf("The day number is 6.\n");
    }
    else if((letter1=="S" || letter1=="s") && (letter2=="u" || letter2=="U") && (letter3=="n" || letter3=="N"))
    {
        printf("The day number is 7.\n");
    }
    else
    {
        printf("Invalid day entered.\n");
    }
}
#include<stdio.h>


int returnDayNumber(char let1, char let2, char let3)
{
    
    if((let1=='M' || let1=='m') && (let2=='o' || let2=='O') && (let3=='n' || let3=='N'))
    {
        return 1;
    }
    else if((let1=='T' || let1=='t') && (let2=='u' || let2=='U') && (let3=='e' || let3=='E'))
    {
        return 2;
    }
    else if((let1=='W' || let1=='w') && (let2=='e' || let2=='E') && (let3=='d' || let3=='D'))
    {
        return 3;
    }
    else if((let1=='T' || let1=='t') && (let2=='h' || let2=='H') && (let3=='u' || let3=='U'))
    {
        return 4;
    }
    else if((let1=='F' || let1=='f') && (let2=='r' || let2=='R') && (let3=='i' || let3=='I'))
    {
        return 5;
    }
    else if((let1=='S' || let1=='s') && (let2=='a' || let2=='A') && (let3=='t' || let3=='T'))
    {
        return 6;
    }
    else if((let1=='S' || let1=='s') && (let2=='u' || let2=='U') && (let3=='n' || let3=='N'))
    {
        return 7;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char letter1,letter2,letter3;
    printf("Enter a day (Mon/Tue/Wed/Thu/Fri/Sat/Sun): ");
    scanf(" %c %c %c", &letter1, &letter2, &letter3);
    int dayNumber = returnDayNumber(letter1, letter2, letter3);
    if(dayNumber != -1)
    {
        printf("The day number is %d.\n", dayNumber);
    }
    else
    {
        printf("Invalid day entered.\n");
    }
}

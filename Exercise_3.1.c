#include<stdio.h>

int main()
{
    printf("Enter number: ");
    int number;
    scanf("%d", &number);
    if (number >= 0)
    {
        printf("The number is positive.\n");
    }
    else
    {
        printf("The number is negative.\n");
    }
}
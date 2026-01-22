#include<stdio.h>

int main()
{
    char a,b,c;
    printf("Enter first initial: ");
    scanf(" %c", &a);
    printf("Enter second initial: ");
    scanf(" %c", &b);
    printf("Enter third initial: ");
    scanf(" %c", &c);
    printf("Your initials are: %c.%c.%c.\n",a,b,c);
}
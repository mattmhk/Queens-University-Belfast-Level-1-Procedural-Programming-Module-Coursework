#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter a number between 10 and 99 :");
    scanf("%d", &a);
    b = a % 10;
    a = a / 10;
    printf("The reversed number is: %d%d\n", b, a);
}
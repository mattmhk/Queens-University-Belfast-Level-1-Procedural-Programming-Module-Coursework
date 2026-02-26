#include<stdio.h>

int main()
{
    char a,b,c;
    printf("Enter first initial:");
    a=getchar();
    getchar();
    printf("Enter second initial:");
    b=getchar();
    getchar();
    printf("Enter third initial:");
    c=getchar();
    printf("Your initials are:");
    putchar(a);
    putchar('.');
    putchar(b);
    putchar('.');
    putchar(c);
    putchar('.');
}


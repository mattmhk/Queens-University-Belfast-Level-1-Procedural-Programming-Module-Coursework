#include <stdio.h>

void printPattern(int stars, int spaces)
{
    if (stars == 0)
        return;

        for(int i = 0; i < spaces; i++)
        printf(" ");

    for(int i = 0; i < stars; i++)
        printf("* ");

    printf("\n");

    printPattern(stars - 1, spaces + 1);
}

int main()
{
    int n = 5;

    printPattern(n, 0);
}
#include<stdio.h>

int main()
{
    printf("Enter value: ");
    int number;
    scanf("%d", &number);
    int no=number>50?1:0;
    printf("Variable reset to %d\n", no);

}
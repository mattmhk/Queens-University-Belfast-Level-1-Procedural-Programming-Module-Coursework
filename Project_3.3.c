#include<stdio.h>

int main()
{
    int number1, number2;
    printf("Enter the two integer numbers: ");
    scanf("%d %d", &number1, &number2);
    if((number1 % 2 == 0) && (number2 % 2 == 0))
    {
        printf("Condition A is true.\n");
    }
    else if((number1 % 2 != 0) && (number2 % 2 != 0))
    {
        printf("Condition B is true.\n");
    }
    else
    {
        printf("Condition C is true.\n");
    }
}
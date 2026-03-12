#include<stdio.h>

int sumOfDigits(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum = sum + (n % 10);
        n = n / 10;       
    }

    return sum;
}

int main()
{
    int num, sum;
    
    printf("Enter an integer number: ");
    scanf("%d", &num);

    sum = sumOfDigits(num);

    printf("The sum of the digits is: %d\n", sum);
}
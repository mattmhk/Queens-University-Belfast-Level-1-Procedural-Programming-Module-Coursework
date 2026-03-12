#include <stdio.h>

int prime(int n)
{
    if (n <= 1)
        return 0;

    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter an integer number to test if it is a prime number: ");
    scanf("%d", &n);

    if(prime(n))
        printf("The number %d is a prime number\n", n);
    else
        printf("The number %d is not a prime number\n", n);
}
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

int generateprimes(int min, int max)
{
    int count = 0;

    for(int i = min; i <= max; i++)
    {
        if(prime(i))
        {
            printf("%d ", i);
            count++;
        }
    }

    return count;
}

int main()
{
    int min, max;

    printf("Enter minimum value: ");
    scanf("%d", &min);

    printf("Enter maximum value: ");
    scanf("%d", &max);

    printf("Prime numbers between %d and %d:\n", min, max);

    int total = generateprimes(min, max);

    printf("\nTotal primes found: %d\n", total);

    return 0;
}
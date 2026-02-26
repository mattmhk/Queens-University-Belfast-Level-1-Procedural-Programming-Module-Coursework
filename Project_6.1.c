#include <stdio.h>
int main()
{
    int fibonnaci[40];
    fibonnaci[0] = 0;
    fibonnaci[1] = 1;
    printf("The first 40 numbers in the Fibonacci sequence are: 0,1");
    for (int i = 2; i < 40; i++)
    {
        fibonnaci[i] = fibonnaci[i-1] + fibonnaci[i-2];
        printf(",%d", fibonnaci[i]);
    }
}
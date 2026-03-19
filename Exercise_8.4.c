#include<stdio.h>
#include<math.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

float myexp(float x, int n)
{
    float sum = 1.0;
    for(int i = 1; i <= n; i++)
    {
        sum += pow(x, i) / factorial(i);
    }
    return sum;
}

int main()
{
    float num,sum=0;
    int terms;
    printf("Enter a value of x to evaluate exp(x) :");
    scanf("%f", &num);
    printf("Enter number of terms of Maclaurin series: ");
    scanf("%d", &terms);
    sum = myexp(num, terms);
    printf("exp(%f) = %f\n", num, sum);
}
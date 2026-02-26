#include<stdio.h>
#include<math.h>

int main()
{
    const float PI=3.14159;
    int n,N;
    printf("Enter the value of N: ");
    scanf("%d",&N);
    for(n = 0; n <= N; n++)
    {
        printf("%.3f\n", cos(2 * PI * (n / (float)N)));
    }
}
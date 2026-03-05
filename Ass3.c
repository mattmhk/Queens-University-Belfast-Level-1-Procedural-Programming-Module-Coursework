#include <stdio.h>

int main()
{
    double x, term, sum = 0.0;
    int N;

    scanf("%lf", &x);
    scanf("%d", &N);

    term = x;  // first term

    for (int n = 1; n <= N; n++)
    {
        sum += term;
        term = -term * x * n / (n + 1);
    }

    printf("%.6f\n", sum);

    return 0;
}
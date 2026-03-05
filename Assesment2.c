#include <stdio.h>

/* NT01012 Procedural Programming	     */
/* Programming Assignment 2          */
/*						     */
/* Question Number: 1			     */
/* Name: 				     */
/* Date: 				     */

int main()
{
    double x;
    int N;

    scanf("%lf", &x);
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("%.6f", 0.0);
        return 0;
    }

    double sum = 1.0;
    double term = 1.0; 

    for (int i = 1; i < N; i++)
    {
        term *= x / i; 
        sum += term;
    }

    printf("%.6f", sum);
    return 0;
}
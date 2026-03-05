/* NT01012 Procedural Programming */
/* Programming Assignment 2 */
/* Question: Mathematical calculation */
/* Name: Zin Lin Htut */
/* Date: 5/02/2026 */

#include <stdio.h>

int main()
{
   double x, term, result = 0.0;  // x = input value, term = current term, result = sum
   int N;                        // number of terms

   scanf("%lf", &x);  
   scanf("%d", &N);   

   term = x;          // first term of the series

   for(int n = 1; n <= N; n++)
   {
       result += term;                      
       term = -term * x * n / (n + 1);      
   }

   printf("%.6f", result);  // print result (6 decimal places)

   
}

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
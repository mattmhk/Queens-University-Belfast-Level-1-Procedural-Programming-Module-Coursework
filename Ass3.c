/* NT01012 Procedural Programming	     */
/* Programming Assignment 3	     */
/*						     */
/* Question Number:			     */
/* Name: 				     */
/* Date: 				     */



#include <stdio.h>

double squareRoot(double x) {
    double guess = 1.0;
    double epsilon = 0.001;

    while ((guess * guess - x > epsilon) || (x - guess * guess > epsilon)) {
        guess = (x / guess + guess) / 2.0;
    }

    return guess;
}

int main() {
    double x;
    scanf("%lf", &x);

    double result = squareRoot(x);
    printf("%.6f", result);

    return 0;
}
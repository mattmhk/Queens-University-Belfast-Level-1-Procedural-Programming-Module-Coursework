#include<stdio.h>
#include<math.h>

double third_side(double b, double c, double A)
{
    return sqrt(b*b + c*c - 2*b*c*cos(A));
}

int main()
{
    double b = 4.0, c = 5.0, A = 60.0;
    printf("Third side: %f\n", third_side(b, c, A));
    return 0;
}
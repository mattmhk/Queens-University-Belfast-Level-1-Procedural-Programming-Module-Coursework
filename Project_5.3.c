#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    double y;
    double new_y;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    y = x / 2;

    while (1)
    {
        new_y = 0.5 * (y + x / y);

        if (fabs(new_y - y) < 0.00001 * y)
            break;

        y = new_y;
    }

    printf("Square root of %.5f is %.5f\n", x, new_y);

    return 0;
}
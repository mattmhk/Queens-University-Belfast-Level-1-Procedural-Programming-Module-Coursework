#include<stdio.h>
#include<math.h>

int main()
{
    float radius, area, circumference;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = M_PI * pow(radius, 2);
    circumference = 2 * M_PI * radius;
    printf("Radius: %f\n", radius);
    printf("Area of the circle: %f\n", area);
    printf("Circumference of the circle: %f\n", circumference);
}

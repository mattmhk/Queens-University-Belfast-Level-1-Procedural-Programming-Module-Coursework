#include<stdio.h>
#define PI 3.14159
int main()
{
    float radius,area,circumference;
    printf("Enter the value of radius: ");
    scanf("%f",&radius);
    area=PI*radius*radius;
    circumference=2*PI*radius;
    printf("Area is %f\n",area);
    printf("Circumference is %f\n",circumference);
}
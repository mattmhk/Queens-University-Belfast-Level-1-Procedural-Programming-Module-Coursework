#include<stdio.h>
#include<math.h>

int main()
{
    float a=sin(0* (M_PI / 180));
    printf("sin(0) = %f\n",a);
    a=sin(45* (M_PI / 180));
    printf("sin(45) = %f\n",a);
    a=sin(90* (M_PI / 180));
    printf("sin(90) = %f\n",a);
}
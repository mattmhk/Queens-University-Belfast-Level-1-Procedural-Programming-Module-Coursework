#include<stdio.h>
#include<math.h>

int main()
{
    float a=pow(sin(50* (180.0 / M_PI)),2);
    printf("sin(50)^2 = %f\n",a);
    float b=pow(cos(50* (180.0 / M_PI)),2);
    printf("cos(50)^2 = %f\n",b);
    float c= a+b;
    printf("sin(50)^2 + cos(50)^2 = %f\n",c);
}
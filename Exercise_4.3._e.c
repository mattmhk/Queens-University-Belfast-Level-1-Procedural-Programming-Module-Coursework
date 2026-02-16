#include<stdio.h>

int main()
{
    float i=-0.0375;
    do
    {
        printf("%f\n", i);
        i=i+0.1225;
    }
    while(i<=1.45);
}
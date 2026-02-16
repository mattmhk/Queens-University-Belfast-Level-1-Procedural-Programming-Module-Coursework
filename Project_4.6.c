#include<stdio.h>
#include<math.h>

int main()
{
    int period, amplitude;
    printf("Enter the period of sine wave (no. of lines vertically): ");
    scanf("%d", &period);
    printf("Enter the amplitude of sine wave (no. of lines horizontally): ");
    scanf("%d", &amplitude);
    int valuediff = 360 / period;
    for (int i = 0; i < period; i++)
    {
        int value = i * valuediff;
        double radians = value * M_PI / 180;
        int spaces = (int)(amplitude * (1 + sin(radians)));
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
}
#include<stdio.h>

int main()
{
    int temp;
    char conversion;
    printf("Enter temperature :");
    scanf("%d", &temp);
    printf("Enter conversion required (f or F to convert to Fahrenheit, c or C to convert to Celsius):");
    scanf(" %c", &conversion);
    if (conversion == 'f' || conversion == 'F')
    {
        int fahrenheit = (temp * 9/5) + 32;
        printf("%d degrees Celsius is equal to %d degrees Fahrenheit\n", temp, fahrenheit);
    }
    else if (conversion == 'c' || conversion == 'C')
    {
        int celsius = (temp - 32) * 5/9;
        printf("%d degrees Fahrenheit is equal to %d degrees Celsius\n", temp, celsius);
    }
    else
    {
        printf("Invalid conversion choice.\n");
    }
}
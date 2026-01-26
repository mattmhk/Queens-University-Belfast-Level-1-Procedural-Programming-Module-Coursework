#include<stdio.h>

int main()
{
    printf("Enter Grade: ");
    char grade;
    scanf(" %c", &grade);
    switch (grade)
    {
        case 'A':
        case 'a':
            printf("Excellent\n");
            break;
        case 'B':
        case 'b':
            printf("Good\n");
            break;
        case 'C':
        case 'c':
            printf("Average\n");
            break;
        case 'D':
        case 'd':
            printf("Poor\n");
            break;
        case 'E':
        case 'e':
            printf("Failing\n");
            break;
        default:
            printf("Invalid Grade\n");
    }
}
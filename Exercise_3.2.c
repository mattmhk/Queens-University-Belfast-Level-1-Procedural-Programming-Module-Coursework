#include<stdio.h>

int main()
{
    printf("Do you want to continue (y/n) or (Y/N): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("You responded YES.\n");
    }
    else
    {
        printf("You responded NO.\n");
    }
}
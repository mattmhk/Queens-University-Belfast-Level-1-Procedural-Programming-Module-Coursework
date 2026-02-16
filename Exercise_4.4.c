#include<stdio.h>

int main()
{
    char i='a';

    while(i!='y'&& i!='n')
    {
        printf("Do you want to continue (y/n)?: ");
        scanf(" %c", &i);
        if(i=='y')
        {
            printf("Thank you, continuing the program...\n");
        }
        else if(i=='n')
        {
            printf("Thank you, exiting the program...\n");
        }
        else
        {
            printf("Response not recognized, try again.\n");
        }
    }
}
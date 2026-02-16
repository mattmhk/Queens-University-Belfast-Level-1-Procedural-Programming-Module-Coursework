#include<stdio.h>

int main()
{
    int i=1;
    for(;;)
    {
        printf("Enter a number (enter 0 to stop): ");
        scanf("%d", &i);
        if(i == 0)
            break;
        printf("%d cubed is %d\n", i, i*i*i);
    }
    printf("Bye for now\n");
}
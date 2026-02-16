#include<stdio.h>

int main()
{
    int num, count=0,sum=0;
    char i='y';
    while(i=='y' || i=='Y')
    {
        num=-10;
        while(num<0 || num>100)
        {
            printf("Enter percentage score: ");
            scanf("%d", &num);
            if(num<0 || num>100)
                printf("Positive scores less than 100 only please.\n");
        }
        sum+=num;
        count++;
        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &i);
    }
    printf("The average is: %d\n", (int)sum/count);

}
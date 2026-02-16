#include<stdio.h>
#include<stdbool.h>

int main()
{
    int num,sum=0;
    bool complete=false;
    printf("Enter an intger number: ");
    scanf("%d", &num);
    while(!complete)
    {
        if(num<10){
            sum+=num;
            complete=true;
        }
        else{
            sum+=num%10;
            num=num/10;
        }
    }
    printf("The sum of the digits is: %d\n", sum);
}
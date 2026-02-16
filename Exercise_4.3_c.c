#include<stdio.h>

int main()
{
    int i=10;
    do
    {
        if(i==1){
            printf("%d\n", i);
            break;
        }
        printf("%d,", i);
        i--;
    }
    while(i>0);
}
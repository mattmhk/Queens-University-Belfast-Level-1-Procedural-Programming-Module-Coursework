#include<stdio.h>

int main()
{
    int i=10;
    while(i>0)
    {
        if(i==1){
            printf("%d\n", i);
            break;
        }
        printf("%d,", i);
        i--;
    }
}
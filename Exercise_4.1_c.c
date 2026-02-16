#include<stdio.h>

int main()
{
    for(int i=10;i>0;i--)
    {
        if(i==1){
            printf("%d\n", i);
            break;
        }
        printf("%d,", i);
    }
}
#include<stdio.h>

int main()
{
    int i=0;

    do
    {
        if(i%2==1)
        {
            printf("%d\n", i);
        }
        i++;
    }
    while(i<=100);
}
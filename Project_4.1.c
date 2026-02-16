#include<stdio.h>
#include<stdbool.h>

int main()
{
    bool prime=true;
    for(int j=2; j<=100; j++)
    {
        prime=true;
        for(int i=1; i<j; i++)
        {
            if(j%i==0 && i!=1)
            {
                prime=false;
                break;
            }
        }
        if(prime)
        {
            printf("%d ", j);
        }
    }
}
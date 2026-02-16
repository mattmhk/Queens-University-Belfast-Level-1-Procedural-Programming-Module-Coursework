#include<stdio.h>

int main()
{
    int i,factorial =1;
    printf(("Which number do u wish to find the factorial of? :"));
    scanf("%d", &i);
    for(int j=1; j<=i; j++)
    {
        factorial *= j;
    }
    if(i==0)
    {
        factorial=1;
    }
    printf("%d! = %d\n", i, factorial);
}
#include<stdio.h>

int main()
{
    float a,b;
    printf("Enter max score possible: ");
    scanf("%f", &a);
    printf("Enter score acheived: ");
    scanf("%f", &b);
    float percentage=b/a*100;
    int percent=percentage;
    printf("You scored %d%% \n",percent);
}
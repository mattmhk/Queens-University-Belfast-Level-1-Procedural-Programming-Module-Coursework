#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter another integer: ");
    scanf("%d", &b);
    int c=a-b;
    printf("%d - %d = %d\n",a,b,c);

    float d,e;
    printf("Enter a float: ");
    scanf("%f", &d);
    printf("Enter another float: ");
    scanf("%f", &e);
    float f=d-e;
    printf("%f - %f = %f\n",d,e,f);

    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter another integer: ");
    scanf("%d", &b);
    c=a*b;
    printf("%d * %d = %d\n",a,b,c);

    printf("Enter a float: ");
    scanf("%f", &d);
    printf("Enter another float: ");
    scanf("%f", &e);
    f=d*e;
    printf("%f * %f = %f\n",d,e,f);

    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter another integer: ");
    scanf("%d", &b);
    c=a/b;
    printf("%d / %d = %d\n",a,b,c);

    printf("Enter a float: ");
    scanf("%f", &d);
    printf("Enter another float: ");
    scanf("%f", &e);
    f=d/e;
    printf("%f / %f = %f\n",d,e,f);

}
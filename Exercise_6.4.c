#include <stdio.h>


int main()
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &num[i]);
    }

    int max=num[0];
    int min=num[0];
    for (int i = 1; i < 10; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
        if (num[i] < min)
        {
            min = num[i];
        }
    }

    printf("The maximum number is %d\n", max);
    printf("The minimum number is %d\n", min);
}

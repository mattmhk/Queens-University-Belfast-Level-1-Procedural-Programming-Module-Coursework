#include <stdio.h>
#include<stdbool.h>

int main()
{
    int size;
    bool valid_input = false;
    
    while(!valid_input)
    {
        printf("Enter the size of the vectors: ");
        if (scanf("%d", &size) == 1 && size > 0 && size <= 100) 
        {
            valid_input = true;
        }
    }

    int scalar_product = 0;
    int x[size], y[size];
    printf("Enter the elements of the first vector:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }


    printf("Enter the elements of the second vector:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &y[i]);
    }


    for (int i = 0; i < size; i++)
    {
        scalar_product += x[i] * y[i];
    }
    printf("The scalar product is %d\n", scalar_product);
}
#include<stdio.h>
#include<math.h>

int main()
{
    int order_amount;
    char product_code;
    printf("Enter Product Code :");
    scanf(" %c", &product_code);
    printf("Order Amount :");
    scanf("%d", &order_amount);
    switch (product_code)
    {
    case 'W':
        printf("Total Cost before discount: %d\n", (int)round(order_amount*12.45));
        if(order_amount<11)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*12.45));
        }
        else if(order_amount<50)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*12.45*0.98));
        }
        else if(order_amount<100)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*12.45*0.95));
        }
        else
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*12.45*0.925));
        }
        break;
    case 'X':
        printf("Total Cost before discount: %d\n", (int)round(order_amount*2.36));
        if(order_amount<11)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*2.36));
        }
        else if(order_amount<50)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*2.36*0.995));
        }
        else if(order_amount<100)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*2.36*0.98));
        }
        else
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*2.36*0.96));
        }
        break;
    case 'Y':
        printf("Total Cost before discount: %d\n", (int)round(order_amount*6.5));
        if(order_amount<11)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*6.5));
        }
        else if(order_amount<50)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*6.5*0.99));
        }
        else if(order_amount<100)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*6.5*0.975));
        }
        else
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*6.5*0.95));
        }
        break;
    case 'Z':
        printf("Total Cost before discount: %d\n", (int)round(order_amount*16.4));
        if(order_amount<11)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*16.4));
        }
        else if(order_amount<50)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*16.4*0.9));
        }
        else if(order_amount<100)
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*16.4*0.875));
        }
        else
        {
            printf("Total Cost after discount: %d\n", (int)round(order_amount*16.4*0.85));
        }
        break;

    default:
        break;
    }
}
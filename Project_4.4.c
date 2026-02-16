#include<stdio.h>
#include<math.h>

int main()
{
    float num,sum=0;
    int terms;
    printf("Enter a value of x to evaluate exp(x) :");
    scanf("%f", &num);
    printf("Enter number of terms of Maclaurin series: ");
    scanf("%d", &terms);
    for(int i=1; i<=terms; i++)
    {
        if(i==1)
        {
            sum++;
            printf("With 1 term, exp(%f) series = %f\n", num, sum);
        }
        else if(i==2){
            sum+=num;
            printf("With 2 terms, exp(%f) series = %f\n", num, sum);
        }
        else{
            int fact=1;
            for(int j=1; j<i; j++)
            {
                fact=fact*j;
            }
            sum+=(pow(num,i-1)/fact);
            printf("With %d terms, exp(%f) series = %f\n", i, num, sum);
        }
    }
   
   
}
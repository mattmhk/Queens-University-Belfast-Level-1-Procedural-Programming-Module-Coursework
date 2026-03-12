#include<stdio.h>

int largest(int arr[], int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int smallest(int arr[], int n)
{
    int min = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int theNumberOfPositiveElements(int arr[], int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, -2, 3, -4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Largest element: %d\n", largest(arr, n));
    printf("Smallest element: %d\n", smallest(arr, n));
    printf("Number of positive elements: %d\n", theNumberOfPositiveElements(arr, n));
}
#include<stdio.h>

int noOfTimesAppeared(char arr[], char target)
{
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == target)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char arr[] = "Hello, World!";
    char target = 'l';
    printf("Number of times '%c' appeared: %d\n", target, noOfTimesAppeared(arr, target));
}
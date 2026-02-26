#include <stdio.h>
#include<stdbool.h>

int main()
{
    int row,column;
    bool valid_input = false;
    while(!valid_input)
    {
        printf("Enter the number of rows: ");
        if (scanf("%d", &row) == 1 && row > 0 && row <= 10) 
        {
            valid_input = true;
        }
    }

    valid_input = false;
    while(!valid_input)
    {
        printf("Enter the number of columns: ");
        if (scanf("%d", &column) == 1 && column > 0 && column <= 10) 
        {
            valid_input = true;
        }
    }

    int matrix1[row][column];
    int matrix2[row][column];
    int matrix3[row][column];
    
    printf("Enter the first matrix:\n");
    for(int i = 0; i < row; i++)
    {
        for (int j=0; j < column; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }


    printf("Enter the second matrix:\n");
    for(int i = 0; i < row; i++)
    {
        for (int j=0; j < column; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }


    for(int i = 0; i < row; i++)
    {
        for (int j=0; j < column; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for(int i = 0; i < row; i++)
    {
        for (int j=0; j < column; j++){
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
}
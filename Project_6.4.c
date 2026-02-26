#include <stdio.h>

int main()
{
    float matrix1[2][2];
    float matrix2[2][2];
    
    printf("Enter a 2x2 matrix:\n");
    for(int i = 0; i < 2; i++)
    {
        for (int j=0; j < 2; j++){
            scanf("%f", &matrix1[i][j]);
        }
    }

    float constant = 1/(matrix1[0][0]*matrix1[1][1] - matrix1[0][1]*matrix1[1][0]);

    printf("The inverse of the matrix is:\n");
    matrix2[0][0] = constant * matrix1[1][1];
    matrix2[0][1] = -constant * matrix1[0][1];
    matrix2[1][0] = -constant * matrix1[1][0];
    matrix2[1][1] = constant * matrix1[0][0];

    for(int i = 0; i < 2; i++)
    {
        for (int j=0; j < 2; j++){
            printf("%.2f ", (float)matrix2[i][j]);
        }
        printf("\n");
    }
}
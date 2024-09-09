#include<stdio.h>

int main()
{
    int r1,c1,r2,c2;
    printf("Enter the number of rows of matrix 1:");
    scanf("%d",&r1);
    printf("Enter the number of columns of matrix 1:");
    scanf("%d",&c1);
    int A[r1][c1];
    printf("Enter the number of rows of matrix 2:");
    scanf("%d",&r2);
    printf("Enter the number of columns of matrix 2:");
    scanf("%d",&c2);
    int B[r1][c1];

    printf("Enter the elements of matrix A:\n");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    if(r2!=c1)
    {
        printf("Matrix Multiplication not possible");
    }

    int C[r2][c1];

    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c1;j++)
        {
            C[i][j]=A[i][j]*B[i][j];
        }
    }

    printf("The elements of product matrix are:");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c1;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
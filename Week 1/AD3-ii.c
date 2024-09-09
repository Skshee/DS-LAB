#include<stdio.h>

int main()
{
   int rows,columns;
    printf("Enter the number of rows:");
    scanf("%d",&rows);
    scanf("%d",&columns);
    int A[rows][columns],B[rows][columns];
    printf("Enter the elements of matrix A:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the elements of matrix B:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    int sum[rows][columns];
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++)
        {
            sum[i][j]=A[i][j]+B[i][j];
        }
    }

    printf("The sum of the matrices are:");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d",sum[i][j]);
        }
    }
} 

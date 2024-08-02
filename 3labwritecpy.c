#include <stdio.h>
void enterData(int arr[][10], int r, int c)
{
    printf("Enter the ele of matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void displayArray(int arr[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void addition(int arr1[][10], int arr2[][10], int result[][10], int r1, int c1)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
void additonDisplay(int arr1[][10], int arr2[][10], int result[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int j = 0;
        while (j < c)
        {
            printf("%d ", arr1[i][j++]);
        }
        printf("\t");
        j = 0;
        while (j < c)
        {
            printf("%d ", arr2[i][j++]);
        }
        printf("\t");
        j = 0;
        while (j < c)
        {
            printf("%d ", result[i][j++]);
        }
        printf("\n");
    }
}
void multiply(int arr1[][10], int arr2[][10], int result[][10], int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}
void tranpose(int arr1[][10], int trans[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            trans[j][i] = arr1[i][j];
        }
    }
}
int main()
{
    printf("Enter the number of rows and colums of matrix A:\n");
    int row1, col1;
    scanf("%d%d", &row1, &col1);
    int A[10][10];
    enterData(A, row1, col1);
    printf("Enter the number of rows and colums of matrix A:\n");
    int row2, col2;
    scanf("%d%d", &row2, &col2);
    int B[10][10];
    enterData(B, row2, col2);
    printf("Displaying Matrix A:\n");
    displayArray(A, row1, col1);
    printf("Displaying Matrix B:\n");
    displayArray(B, row2, col2);
    int counter = 0, key, key1;
    while (counter != 1)
    {
        printf("\nEnter'1'for addition of two matrices\n");
        printf("Enter'2'for multiplication of two matrices\n");
        printf("Enter'3'for finding tranpose of matrices\n");
        printf("Enter'4' to exit!\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            if (row1 == row2 && col1 == col2)
            {
                int C[10][10];
                addition(A, B, C, row1, col1);
                printf("\nDisplaying:\n");
                additonDisplay(A, B, C, row1, col1);
            }
            else
            {
                printf("Not possible!\n");
            }

            break;
        case 2:
            if (row2 == col1)
            {
                int D[10][10];
                multiply(A, B, D, row1, col1, row2, col2);
                printf("Displaying resultant array:\n");
                displayArray(D, row1, col2);
            }
            else
            {
                printf("Not possible!\n");
            }
            break;
        case 3:
            printf("Enter '1' for displaying tranpose of Matrix 'A'\n");
            printf("Enter '2' for displaying tranpose of Matrix 'B'\n");
            scanf("%d", &key1);
            int E[10][10];
            if (key1 == 1)
            {
                tranpose(A, E, row1, col1);
                displayArray(E, col1, row1);
            }
            else if (key1 == 2)
            {
                tranpose(B, E, row2, col2);
                displayArray(E, col2, row2);
            }
            break;
        case 4:
            counter = 1;
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}
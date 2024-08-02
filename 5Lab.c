#include <stdio.h>
int main()
{
    int m, n, i, j;
    printf("Enter the rows and columns of a matrix\n");
    scanf("%d", &m);
    scanf("%d", &n);
    int matrix[m][n];
    printf("Enter the elements of a matrix\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }
    printf("Given matrix is\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\nSpiral print of matrix is\n");
    int row_start = 0, col_start = 0, row_end = m - 1, col_end = n - 1, row, col;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (col = col_start; col <= col_end; col++)
            printf("%d ", matrix[row_start][col]);

        row_start++;
        for (row = row_start; row <= row_end; row++)
            printf("%d ", matrix[row][col_end]);

        col_end--;
        for (col = col_end; col >= col_start; col--)
            printf("%d ", matrix[row_end][col]);

        row_end--;
        for (row = row_end; row >= row_start; row--)
            printf("%d ", matrix[row][col_start]);

        col_start++;
    }
}
#include <stdio.h>
void main()
{
    int r, c, size = 0;
    printf("Enter the matrix row: ");
    scanf("%d", &r);
    printf("Enter the matrix column: ");
    scanf("%d", &c);
    int sparse[r][c];
    printf("Enter array elements: ");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &sparse[i][j]);
            if (sparse[i][j] != 0)
                size++;
        }
    if ((size < (r * c) / 2) && (size < c || size < r))
    {
        int matrix[3][size], k = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (sparse[i][j] != 0)
                {
                    matrix[0][k] = i;
                    matrix[1][k] = j;
                    matrix[2][k] = sparse[i][j];
                    k++;
                }
        printf("Original Matrix: \n");
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%d\t", matrix[i][j]);
            printf("\n");
        }
        printf("Sparse Matrix: \n");
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%d\t", sparse[i][j]);
            printf("\n");
        }
    }
    else
        printf("Sparse Matrix not possible");
}
#include <stdio.h>

void main()
{
    int i, j, k, r, c, sum = 0, arr1[10][10], arr2[10][10], arr3[10][10];

    printf("\nEnter the no of rows and columns:\n");
    scanf("%d %d", &r, &c);
    printf("Enter the elements:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the elements:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < c; k++)
            {
                sum = sum + arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = sum;
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
        printf("\n");
    }
}
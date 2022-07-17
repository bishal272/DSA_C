#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p, n, i;
    printf("Enter the length of array;\n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("the array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(p + i));
    }
}
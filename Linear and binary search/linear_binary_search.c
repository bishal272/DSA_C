#include <stdio.h>
#include <stdlib.h>

int lsIt(int[], int, int);
int lsRc(int[], int, int, int);
int bsIt(int[], int, int, int);
int bsRc(int[], int, int, int);

void main()
{

    int search, n;
    printf("Enter the length of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the value to search:\n");
    scanf("%d", &search);

    int ch = 0;
    while (ch != 5)
    {

        printf("\n1.linear search iterative\n2.linear search recursive\n3.binary search iterative\n4.binary search recursive\n5.exit\n");
        printf("\nEnter the choice:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            lsIt(arr, n, search);
            break;
        case 2:
            lsRc(arr, 0, n, search);
            break;
        case 3:
            int res = bsIt(arr, 0, n, search);
            if (res == -1)
            {
                printf("\nNot found\n");
            }
            else
            {
                printf("\nThe %d is found at %d position\n", search, res);
            }
            break;
        case 4:
            int res1 = bsRc(arr, 0, n, search);
            if (res1 == -1)
            {
                printf("\nNot found\n");
            }
            else
            {
                printf("\nThe %d is found at %d position\n", search, res1);
            }
            break;
        case 5:
            exit(0);

        default:
            printf("\nEnter valid option:\n");
            break;
        }
    }
}
int lsIt(int arr[], int n, int search)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            printf("\nThe %d is found at %d position\n", search, i + 1);
            break;
        }
        if (i == n - 1)
        {
            printf("\nNot present\n");
        }
    }
    return 0;
}

int lsRc(int arr[], int index, int n, int search)
{

    if (index >= n)
    {
        printf("\nNot present\n");
    }
    else if (arr[index] == search)
    {
        printf("\nThe %d is found at %d position\n", search, (index + 1));
    }
    else
    {
        return lsRc(arr, index + 1, n, search);
    }
    return 0;
}

int bsIt(int arr[], int lb, int ub, int search)
{
    while (lb <= ub)
    {
        int mid = (ub + lb) / 2;
        if (arr[mid] == search)
        {
            return mid + 1;
            break;
        }
        else if (arr[mid] > search)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return -1;
}

int bsRc(int arr[], int lb, int ub, int search)
{
    if (lb <= ub)
    {
        int mid = (ub + lb) / 2;
        if (arr[mid] == search)
        {
            return mid + 1;
        }
        else if (arr[mid] > search)
        {
            return bsRc(arr, lb, mid - 1, search);
        }
        else
        {
            return bsRc(arr, mid + 1, ub, search);
        }
    }
    return -1;
}
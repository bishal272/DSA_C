#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start;

void insert_beg();
void insert_loc();
void insert_end();
void delete_beg();
void delete_loc();
void delete_end();
void show();

void main()
{
    int ch = 0;
    while (ch != 8)
    {
        printf("\nEnter the operation to perform:\n");
        printf("\n  1.insert begining\n  2.insert at a location\n  3.insert at the end\n  4.Delete from Beginning\n  5.Delete from last\n  6.Delete node after specified location\n  7.Show\n  8.Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_loc();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_loc();
            break;
        case 7:
            show();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Enter valid option");
        }
    }
}

void insert_beg()
{
    struct node *p;
    int value;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("\n Overflow\n");
    }
    else
    {
        printf("\nEnter the value :\n");
        scanf("%d", &value);

        if (start == NULL)
        {
            p->data = value;
            p->prev = NULL;
            p->next = NULL;
            start = p;
        }
        else
        {
            p->data = value;
            p->next = start;
            p->prev = NULL;
            start->prev = p;
            start = p;
        }
    }
}

void insert_loc()
{
    struct node *p, *temp;
    int i, loc, value;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("\n Overflow");
    }
    else
    {
        temp = start;
        printf("\nEnter the location after which to enter:\n");
        scanf("%d", &loc);
        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nThere are less than %d elements\n");
                return;
            }
        }
        printf("\nEnter the value:\n");
        scanf("%d", &value);
        p->data = value;
        p->next = temp->next;
        temp->next->prev = p;
        temp->next = p;
        p->prev = temp;
    }
}

void insert_end()
{
    struct node *p, *temp;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the value:\n");
        scanf("%d", &value);
        p->data = value;
        if (start == NULL)
        {
            p->next = NULL;
            p->prev = NULL;
            start = p;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
            p->prev = temp;
            p->next = NULL;
        }
    }
}

void delete_beg()
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else if (start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        p = start;
        p->next->prev = NULL;
        start = p->next;
        free(p);
    }
}

void delete_loc()
{
    struct node *p, *temp;
    int value;
    printf("\nEnter the data after which to delete:\n");
    scanf("%d", &value);
    p = start;
    if (start == NULL)
    {
        printf("Empty list");
    }
    else
    {
        while (p->data != value)
        {
            p = p->next;
        }

        if (p->next == NULL)
        {
            printf("\nCan't delete\n");
        }
        else if (p->next->next == NULL)
        {
            p->next = NULL;
        }
        else
        {
            temp = p->next;
            p->next = temp->next;
            temp->next->prev = p;
            free(temp);
        }
    }
}

void delete_end()
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nEmpty list\n");
    }
    else if (start->next == NULL)
    {

        free(start);
        start = NULL;
    }
    else
    {
        p = start;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
    }
}

void show()
{
    struct node *p;
    p = start;
    if (p == NULL)
    {
        printf("\n Nothing to print\n");
    }
    else
    {
        printf("\nThe values in the linked list are:\n");
        while (p != NULL)
        {

            printf("\n%d\n", p->data);
            p = p->next;
        }
    }
}
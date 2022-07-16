#include <stdio.h>
#include <stdlib.h>

struct node
{
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
        printf("\n\nEnter the operation to perform:\n");
        printf("\n  1.insert begining\n  2.insert at a location\n  3.insert at the end\n  4.Delete from Beginning\n  5.Delete from last\n  6.Delete node after specified location\n  7.Show\n  8.Exit\n");
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
        printf("Overflow\n");
    }
    else
    {
        printf("\nEnter the value:\n");
        scanf("%d", &value);

        p->data = value;
        p->next = start;
        start = p;
    }
}

void insert_loc()
{
    int i, loc, value;
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("overflow");
    }
    else
    {
        printf("\n enter the value:\n");
        scanf("%d", &value);
        p->data = value;
        printf("\nenter the location after which to insert:\n");
        scanf("\n%d", &loc);

        temp = start;
        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Can't insert");
                return;
            }
        }
        p->next = temp->next;
        temp->next = p;
    }
}

void insert_end()
{
    struct node *p, *temp;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("overflow");
    }
    else
    {
        printf("\n Enter the value:\n");
        scanf("%d", &value);
        p->data = value;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        p->next = NULL;
        temp->next = p;
    }
}

void delete_beg()
{
    struct node *p;

    if (start == NULL)
    {
        printf("Empty list");
    }
    else
    {
        p = start;
        start = p->next;
        free(p);
    }
}

void delete_end()
{
    struct node *p, *p1;
    if (start == NULL)
    {
        printf("empty list");
    }
    else if (start->next == NULL)
    {
        start = NULL;
        free(start);
        printf("Only node deleted\n");
    }
    else
    {
        p = start;
        while (p->next != NULL)
        {
            p1 = p;
            p = p->next;
        }
        p1->next = NULL;
        free(p);
    }
}

void delete_loc()
{
    struct node *p, *p1;
    int i, loc;
    printf("\nEnter the location to delete after:\n");
    scanf("%d", &loc);
    p = start;
    for (i = 0; i < loc; i++)
    {
        p1 = p;
        p = p->next;
        if (p == NULL)
        {
            printf("cant delete");
            return;
        }
    }
    p1->next = p->next;
    free(p);
}

void show()
{
    struct node *p;
    p = start;
    if (p == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (p != NULL)
        {
            printf("\n%d", p->data);
            p = p->next;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX], top = -1;
void push();
void pop();
void peep();
void display();
void update();

void main()
{
    int ch = 0;
    while (ch != 6)
    {
        printf("\nEnter the operation to perform:\n");
        printf("\n1.push\n2.pop\n3.peep\n4.display\n5.Update\n6.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            update();
            break;
        case 6:
            exit(0);
        default:
            printf("Enter valid option\n");
            break;
        }
    }
}

void push()
{
    int value;
    if (top == MAX - 1)
    {
        printf("\n Overflow\n");
    }
    else
    {
        printf("\nEnter the value:\n");
        scanf("%d", &value);
        top = top + 1;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        printf("The element %d is popped", stack[top]);
        top = top - 1;
    }
}

void peep()
{
    if (top == -1)
    {
        printf("Empty stack\n");
        return;
    }
    else
    {
        printf("The peep from the stack is %d", stack[top]);
    }
}

void update()
{
    int pos, value;
    if (top == -1)
    {
        printf("Empty stack\n");
    }
    else
    {
        printf("\nEnter the position to update:\n");
        scanf("%d", &pos);
        if (top - pos == -1)
        {
            printf("\nthe position doesn't exist\n");
            return;
        }
        else
        {
            printf("\nEnter the new value:\n");
            scanf("%d", &value);
            stack[top - pos + 1] = value;
            printf("Value updated!\n");
        }
    }
}

void display()
{
    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\t%d\n", stack[i]);
        }
    }
    else
    {
        printf("the stack is empty\n");
    }
}
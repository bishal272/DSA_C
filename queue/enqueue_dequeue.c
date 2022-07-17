#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q[MAX], rear = -1, front = -1;
void enqueue();
void dequeue();
void show();

void main()
{
    int ch = 0;
    while (ch != 4)
    {
        printf("\n1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}

void enqueue()
{
    int value;
    if (rear == MAX - 1)
    {
        printf("\n overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("Enter the value:\n");
        scanf("%d", &value);
        rear = rear + 1;
        q[rear] = value;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Empty queue\n");
        return;
    }
    else
    {
        printf("The deleted element is %d \n", q[front]);
        front = front + 1;
    }
}

void show()
{
    if (front == -1 || front > rear)
    {
        printf("Empty list nothing to print\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
        printf("\n");
    }
}
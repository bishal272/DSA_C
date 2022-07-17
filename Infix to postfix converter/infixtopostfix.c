#include <stdio.h>
#include <ctype.h>
// text using A+(B*C-(D/E^F)*G)*H

char stack[100];
int top = -1;

char push(char);
char pop();
int priority(char);

void main()
{
    char exp[100];
    char *e, x;
    printf("Enter the infix expression:\n");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}

char push(char x)
{
    top = top + 1;
    stack[top] = x;
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char ch)
{
    if(ch == '(')
        return 0;
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    return 0;
}

void main()
{
    char infix[100];
    char *ptr, ch;
    printf("\n Enter the expression : ");
    scanf("%s",infix);
    ptr = infix;
    printf("\n Stack Equals \n ");

    while(*ptr != '\0')
    {
        if(isalnum(*ptr))
            printf("%c ",*ptr);
        else if(*ptr == '(')
            push(*ptr);
        else if(*ptr == ')')
        {
            while((ch = pop()) != '(')
                printf("%c ", ch);
        }
        else
        {
            while(priority(stack[top]) >= priority(*ptr))
                printf("%c ",pop());
            push(*ptr);
        }
        ptr++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }
}
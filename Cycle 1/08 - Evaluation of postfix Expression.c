#include <stdio.h>
#include <ctype.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int operation(int a, int b, int current_character)
{
    switch (current_character)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}
void main()
{
    char exp[20], x;
    int num;
    printf("Enter the expression: ");
    scanf("%s", exp);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isalnum(exp[i]))
        {
            num = exp[i] - 48;
            push(num);
        }
        else
            push(operation(pop(), pop(), exp[i]));
    }
    printf("The result of %s is %d", exp, pop());
}
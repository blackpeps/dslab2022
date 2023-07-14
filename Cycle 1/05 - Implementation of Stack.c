#include <stdio.h>
#define max 3
void push();
void pop();
void display();
int stack[max], top = -1;
void main()
{
    int ch;
    printf("Stack\n");
    while (1)
    {
        printf("\n1. Push\t2. Pop\t3. Display\t4. Exit\tOption: ");
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
            display();
            break;
        case 4:
            printf("Program is exiting...");
            return;
        default:
            printf("Invalid input!");
        }
    }
}
void push()
{
    if (top == max)
        printf("Overflow");
    else
    {
        if (top <= -1)
            top = 0;
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        printf("Element %d has been pushed at %d", element, top);
        stack[top++] = element;
    }
}
void pop()
{
    if (top <= 0)
        printf("Underflow");
    else
        printf("Element %d has been popped out.", stack[--top]);
}
void display()
{
    if (top <= 0)
        printf("Stack is empty");
    else
    {
        printf("The stack is \n");
        for (int i = 0; i < top; i++)
            printf("%d\t", stack[i]);
    }
}
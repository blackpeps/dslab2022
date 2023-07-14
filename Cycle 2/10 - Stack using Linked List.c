#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;
void push(int);
void pop();
void display();
void main()
{
    int ch, val;
    printf("Stack Using Linked List");
    for (;;)
    {
        printf("\n1.Push\t2.Pop\t3.Display\t4.Exit\tChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("Invalid Input");
        }
    }
}
void push(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if (top == NULL)
        newnode->next = NULL;
    else
        newnode->next = top;
    top = newnode;
}
void pop()
{
    if (top == NULL)
        printf("Empty Stack");
    else
    {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}
void display()
{
    if (top == NULL)
        printf("Empty Stack");
    else
    {
        struct node *temp = top;
        printf("Stack from top: ");
        while (temp->next != NULL)
        {
            printf("%d<---", temp->data);
            temp = temp->next;
        }
        printf("%d<---NULL", temp->data);
    }
}
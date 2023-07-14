#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;
void enQ(int);
void deQ();
void display();
void main()
{
    int ch, val;
    printf("Queue using Linked List");
    for (;;)
    {
        printf("\n1.enQ\t2.deQ\t3.Display\t4.Exit\tChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enQ(val);
            break;
        case 2:
            deQ();
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
void enQ(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void deQ()
{
    if (front == NULL)
        printf("Empty Q");
    else
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}
void display()
{
    if (front == NULL)
        printf("Empty Q");
    else
    {
        struct node *temp = front;
        printf("Queue: ");
        for (temp; temp->next != NULL; temp = temp->next)
            printf("%d--->", temp->data);
        printf("%d--->NULL", temp->data);
    }
}
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data, priority;
    struct node *next;
} *front = NULL;
void enQ(int, int);
void deQ();
void display();
void main()
{
    int ch, val, prio;
    printf("Priority Queue using Linked List");
    for (;;)
    {
        printf("\n1.enQ\t2.deQ\t3.Display\t4.Exit\tChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter priority: ");
            scanf("%d", &prio);
            enQ(val, prio);
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
void enQ(int val, int prio)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->priority = prio;
    if (front == NULL || prio < front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        struct node *temp = front;
        while (temp->next != NULL && temp->next->priority <= prio)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
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
            printf("%d(%d)--->", temp->data, temp->priority);
        printf("%d(%d)--->NULL", temp->data, temp->priority);
    }
}
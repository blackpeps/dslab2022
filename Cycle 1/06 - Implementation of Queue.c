#include <stdio.h>
#define MAX 5
int q[MAX], rear = -1, front = -1;
void insert();
void delete();
void display();
void main()
{
    int ch;
    printf("Queue\n");
    while (1)
    {
        printf("\n1. Push\t2. Pop\t3. Display\t4. Exit\tOption: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Program is exiting...\n");
            return;
        default:
            printf("Invalid input!");
        }
    }
}
void insert()
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Enter new element: ");
        scanf("%d", &q[++rear]);
    }
}
void delete()
{
    if (front == -1)
        printf("Queue Underflow");
    else
    {
        printf("Element %d is deleted\n", q[front++]);
        if (front > rear)
            front = rear = -1;
    }
}
void display()
{
    if (front == -1 || front > rear)
        printf("Queue is Empty");
    else
    {
        printf("Queue is :");
        for (int i = front; i <= rear; i++)
            printf(" %d", q[i]);
    }
}
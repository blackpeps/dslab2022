#include <stdio.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
void enQueue(int element)
{
    if (isFull())
        printf("\nQueue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d", element);
    }
}
void deQueue()
{
    int element;
    if (isEmpty())
    {
        printf("\nQueue is empty !! \n");
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE;
        printf("\nDeleted -> %d \n", element);
    }
}
void display()
{
    int i;
    if (isEmpty())
        printf(" \nEmpty Queue\n");
    else
    {
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", items[i]);
        printf("%d ", items[i]);
    }
}
int main()
{
    int ch, x;
    printf("Circular Queue");
    while (1)
    {
        printf("\n1. Insert\t 2. Delete\t3. Display\t4. Exit\tChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted");
            scanf("%d", &x);
            enQueue(x);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice \n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtSpecific(int, int);
void removeAtBeginning();
void removeAtEnd();
void removeAtSpecific(int);
void display();
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void main()
{
    int choice, value, location;
    printf("Circular Queue using Linked List");
    while (1)
    {
        printf("\nA.Insert:\t1.At Beginning\t2.At End\t3.At Specific Location");
        printf("\nB.Delete:\t4.At Beginning\t5.At End\t6.At Specific Location");
        printf("\n7.Display\t8.Exit\tChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            printf("Enter where to put: ");
            scanf("%d", &location);
            insertAtSpecific(value, location);
            break;
        case 4:
            removeAtBeginning();
            break;
        case 5:
            removeAtEnd();
            break;
        case 6:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            removeAtSpecific(value);
            break;
        case 7:
            display();
            break;
        case 8:
            return;
        default:
            printf("Invalid Choice");
        }
    }
}
void insertAtBeginning(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
}
void insertAtEnd(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
}
void insertAtSpecific(int value, int location)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->data != location)
        {
            if (temp->next == head)
            {
                printf("Given node is not found in the list");
                return;
            }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void removeAtBeginning()
{
    if (head == NULL)
        printf("List is Empty");
    else
    {
        struct node *temp1 = head, *temp2 = head;
        if (temp1->next == head)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while (temp1->next != head)
                temp1 = temp1->next;
            head = temp2->next;
            temp1->next = head;
            free(temp2);
        }
    }
}
void removeAtEnd()
{
    if (head == NULL)
        printf("List is Empty");
    else
    {
        struct node *temp1 = head, *temp2;
        if (temp1->next == head)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while (temp1->next != head)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = head;
            free(temp1);
        }
    }
}
void removeAtSpecific(int value)
{
    if (head == NULL)
        printf("List is Empty");
    else
    {
        struct node *temp1 = head, *temp2;
        while (temp1->data != value)
        {
            if (temp1->next == head)
            {
                printf("\nValue not found!!!\n");
                return;
            }
            else
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
        }
        if (temp1 == head && temp1->next == head)
            head = NULL;
        else if (temp1 == head)
        {
            while (temp2->next != head)
                temp2 = temp2->next;
            head = temp1->next;
            temp2->next = head;
        }
        else if (temp1->next == head)
            temp2->next = head;
        else
            temp2->next = temp1->next;
        free(temp1);
    }
}
void display()
{
    if (head == NULL)
        printf("Empty Linked list");
    else
    {
        struct node *temp = head;
        printf("Linked list is: ");
        while (temp->next != head)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->head", temp->data);
    }
}

#include <stdio.h>
#include <stdlib.h>
void inB(int);
void inE(int);
void inS(int, int);
void deB();
void deE();
void deS(int);
void dis();
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void main()
{
    int ch, val, loc;
    printf("Singly Linked List");
    for (;;)
    {
        printf("\nA.Insert:\t1.At Beginning\t2.At End\t3.At Specific Location");
        printf("\nB.Delete:\t4.At Beginning\t5.At End\t6.At Specific Location");
        printf("\n7.Display\t8.Exit\tChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            inB(val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            inE(val);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter location: ");
            scanf("%d", &loc);
            inS(val, loc);
            break;
        case 4:
            deB();
            break;
        case 5:
            deE();
            break;
        case 6:
            printf("Enter value: ");
            scanf("%d", &val);
            deS(val);
        case 7:
            dis();
            break;
        case 8:
            return;
        default:
            printf("Invalid input");
        }
    }
}
void inB(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if (head == NULL)
        newnode->next = NULL;
    else
        newnode->next = head;
    head = newnode;
}
void inE(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void inS(int val, int loc)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->data != loc)
            temp = temp->next;
        if (temp == NULL)
        {
            printf("Element not found");
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deB()
{
    if (head == NULL)
        printf("Empty List");
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
void deE()
{
    if (head == NULL)
        printf("Empty List");
    else
    {
        struct node *temp1 = head, *temp2 = NULL;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == head)
            head = NULL;
        else if (temp2 != NULL)
            temp2->next = NULL;
        free(temp1);
    }
}
void deS(int val)
{
    if (head == NULL)
        printf("Empty List");
    else
    {
        struct node *temp1 = head, *temp2 = NULL;
        while (temp1->data != val)
        {
            if (temp1->next == NULL)
            {
                printf("Element not found");
                return;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == head)
            head = temp1->next;
        else
            temp2->next = temp1->next;
        free(temp1);
    }
}
void dis()
{
    if (head == NULL)
        printf("Empty List");
    else
    {
        struct node *temp = head;
        printf("List: ");
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL", temp->data);
    }
}
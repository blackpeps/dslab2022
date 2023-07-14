#include <stdio.h>
#include <stdlib.h>
#define table_size 5
struct node
{
    int data;
    struct node *next;
} *head[table_size] = {NULL}, *temp;
void insert()
{
    int i, key;
    printf("Enter a value to insert: ");
    scanf("%d", &key);
    i = key % table_size;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    if (head[i] == NULL)
        head[i] = newnode;
    else
    {
        temp = head[i];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void search()
{
    int key, index;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    index = key % table_size;
    if (head[index] == NULL)
        printf("Search element doesn't exist");
    else
    {
        for (temp = head[index]; temp != NULL; temp = temp->next)
        {
            if (temp->data == key)
            {
                printf("Search element found");
                break;
            }
        }
        if (temp == NULL)
            printf("Search element doesn't exist");
    }
}
void display()
{
    printf("Index\t\tHash Entry");
    printf("\n------\t\t-----------");
    for (int i = 0; i < table_size; i++)
    {
        printf("\n%d", i);
        if (head[i] == NULL)
        {
            printf("\t\tNo hash entry found");
        }
        else
        {
            printf("\t\t");
            for (temp = head[i]; temp->next != NULL; temp = temp->next)
                printf("%d->", temp->data);
            if (temp->next == NULL)
                printf("%d ", temp->data);
        }
    }
}
void main()
{
    int key, choice;
    for (;;)
    {
        printf("\n1.Insert\t2.Display\t3.Search\t4.Exit\tChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#define table_size 5
int h[table_size] = {0};
void insert()
{
    int key, index, i, hkey;
    printf("Enter a value:");
    scanf("%d", &key);
    hkey = key % table_size;
    for (i = 0; i < table_size; i++)
    {
        index = (hkey + i) % table_size;
        if (h[index] == 0)
        {
            h[index] = key;
            break;
        }
    }
    if (i == table_size)
        printf("Element not inserted...");
}
void search()
{
    int key, index, i, hkey;
    printf("Enter search element: ");
    scanf("%d", &key);
    hkey = key % table_size;
    for (i = 0; i < table_size; i++)
    {
        index = (hkey + i) % table_size;
        if (h[index] == key)
        {
            printf("Value found at index %d", index);
            break;
        }
    }
    if (i == table_size)
        printf("Element not found...");
}
void display()
{
    printf("\nElements in hash table are: ");
    printf("\nindex\t\tValues");
    printf("\n------\t\t-------");
    for (int i = 0; i < table_size; i++)
        printf("\n%d\t\t%d", i, h[i]);
}
void main()
{
    int choice;
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
            printf("Invalid Choice");
        }
    }
}
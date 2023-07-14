#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;
struct Node *search(int data);
void insert(int);
struct Node *minValueNode(struct Node *);
struct Node *deleteNode(struct Node *, int);
void inOrder(struct Node *);
void preOrder(struct Node *);
void postOrder(struct Node *);
void main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Insert\t2.search\t3.inOrder\t4.preOrder\t5.postOrder\t6.Delete\t7.Exit\tChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("\nEnter the value to be search: ");
            scanf("%d", &value);
            struct Node *x = search(value);
            if (x != NULL)
                printf("Found");
            else
                printf("Not found");
            break;
        case 3:
            inOrder(root);
            break;
        case 4:
            preOrder(root);
            break;
        case 5:
            postOrder(root);
            break;
        case 6:
            printf("\nEnter the value to be delete: ");
            scanf("%d", &value);
            deleteNode(root, value);
            break;
        case 7:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}
struct Node *minValueNode(struct Node *root)
{
    struct Node *current = root;
    if (current->left != NULL)
        current = current->left;
    return current;
}
struct Node *search(int data)
{
    struct Node *current = root;
    printf("Visiting elements: ");
    while (current->data != data)
    {
        if (current != NULL)
        {
            printf("%d ", current->data);
            if (current->data > data)
                current = current->left;
            else
                current = current->right;
            if (current == NULL)
                return NULL;
        }
    }
    return current;
}
void insert(int data)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current, *parent;
    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    if (root == NULL)
        root = tempNode;
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = tempNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = tempNode;
                    return;
                }
            }
        }
    }
}
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        printf("Given node not found");
    else
    {
        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else
        {
            if (root->left == NULL)
            {
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                struct Node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                struct Node *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
    }
    return root;
}
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
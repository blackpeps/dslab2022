#include <stdio.h>
#include <stdlib.h>
int source, V, E, visited[20], A[20][20], Q[20], S[20], front = -1, rear = -1, top = -1;
void push(int item)
{
    top++;
    S[top] = item;
}
int pop()
{
    int item;
    if (top = -1)
        return -1;
    else
        return S[top--];
}
void enqueue(int item)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        Q[rear] = item;
    }
    else
    {
        rear++;
        Q[rear] = item;
    }
}
int dequeue()
{
    int item;
    if (front == -1 && rear == -1)
        return -1;
    else if (front == rear)
    {
        item = Q[front];
        front = rear = -1;
        return item;
    }
    else
        return Q[front++];
}
void DFS(int i)
{
    int j, s;
    visited[i] = 1;
    push(i);
    while (top != -1)
    {
        s = S[top];
        for (i = 1; i <= V; i++)
            if (A[s][i] == 1 && visited[i] == 0)
            {
                printf("%d-->%d\t", s, i);
                DFS(i);
            }
        pop();
    }
}
void BFS(int s)
{
    visited[s] = 1;
    enqueue(s);
    while (front != -1)
    {
        s = dequeue();
        for (int i = 1; i <= V; i++)
            if (A[s][i] == 1 && visited[i] == 0)
            {
                printf("%d-->%d\t", s, i);
                visited[i] = 1;
                enqueue(i);
            }
    }
}
void main()
{
    int i, j, v1, v2, opt;
    printf("Enter vertices: ");
    scanf("%d", &V);
    for (i = 1; i <= V; i++)
        for (j = 0; j <= V; j++)
            A[i][j] = 0;
    printf("Enter edges: ");
    scanf("%d", &E);
    printf("Enter edges format:\n");
    for (i = 1; i <= E; i++)
    {
        printf("v1 v2: ");
        scanf("%d%d", &v1, &v2);
        A[v1][v2] = 1;
    }
    printf("Adjacency matrix is\n");
    for (i = 1; i <= V; i++)
    {
        for (j = 1; j <= V; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
    for (i = 1; i <= V; i++)
        visited[i] = 0;
    printf("Enter source: ");
    scanf("%d", &source);
    printf("DFS:\t");
    DFS(source);
    for (i = 1; i <= V; i++)
        visited[i] = 0;
    printf("\nBFS\t");
    BFS(source);
}
#include <stdio.h>
void sort(int n, int a[])
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void printList(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}
void main()
{
    int n;
    printf("Enter array limit: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Unsorted array: ");
    printList(n, a);
    sort(n, a);
    printf("Sorted Array: ");
    printList(n, a);
}
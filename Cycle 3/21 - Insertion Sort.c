#include <stdio.h>
void sort(int n, int a[])
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && temp < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
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
#include <stdio.h>
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
void main()
{
    int count;
    printf("Enter array limit: ");
    scanf("%d", &count);
    int array[count];
    printf("Enter array elements: ");
    for (int i = 0; i < count; i++)
        scanf("%d", &array[i]);
    printf("\nUnsorted elements:\t");
    for (int i = 0; i < count; i++)
        printf(" %d", array[i]);
    heapSort(array, count);
    printf("\nSorted elements:\t");
    for (int i = 0; i < count; i++)
        printf(" %d", array[i]);
}
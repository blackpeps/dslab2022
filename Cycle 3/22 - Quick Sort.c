#include <stdio.h>
void quicksort(int array[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (array[i] <= array[pivot] && i < last)
                i++;
            while (array[j] > array[pivot])
                j--;
            if (i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quicksort(array, first, j - 1);
        quicksort(array, j + 1, last);
    }
}
void main()
{
    int i, count;
    printf("Enter array limit: ");
    scanf("%d", &count);
    int array[count];
    printf("Enter array elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &array[i]);
    printf("Unsorted elements:\t");
    for (i = 0; i < count; i++)
        printf(" %d", array[i]);
    quicksort(array, 0, count - 1);
    printf("\nSorted elements:\t");
    for (i = 0; i < count; i++)
        printf(" %d", array[i]);
}
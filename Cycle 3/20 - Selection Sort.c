#include <stdio.h>
void main()
{
    int n, temp;
    printf("Enter array limit: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array elements are: \n");
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (a[j] > a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
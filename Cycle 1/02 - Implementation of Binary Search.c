#include <stdio.h>
int main()
{
    int i, low, high, mid, n, key, array[100];
    printf("Enter array limit: ");
    scanf("%d", &n);
    printf("Enter array elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter the array element to be searched: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (array[mid] < key)
            low = mid + 1;
        else if (array[mid] == key)
        {
            printf("%d found at %d.\n", key, mid + 1);
            break;
        }
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if (low > high)
        printf("%d not found.\n", key);
    return 0;
}
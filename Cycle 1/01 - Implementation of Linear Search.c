#include <stdio.h>
int main()
{
    int n, s, flag = 0;
    printf("Enter array limit: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array elements are: \n");
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    printf("Enter the array element to be searched: ");
    scanf("%d", &s);
    for (int i = 0; i < n; i++)
        if (s == a[i])
        {
            printf("%d found at %d", s, i + 1);
            flag = 1;
            break;
        }
    if (flag == 0)
        printf("%d not found.\n", s);
    return 0;
}
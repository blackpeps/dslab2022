#include <stdio.h>
struct poly
{
    int coeff;
    int exp;
};
void main()
{
    struct poly a[50], b[50], c[50];
    int i, deg1, deg2;
    printf("Enter the degree for polynomial 1: ");
    scanf("%d", &deg1);
    printf("Enter the coefficients:\n");
    for (i = 0; i <= deg1; i++)
    {
        printf("x^%d: ", i);
        scanf("%d", &a[i].coeff);
        a[i].exp = i;
    }
    printf("Enter the degree for polynomial 2: ");
    scanf("%d", &deg2);
    printf("Enter the coefficients:\n");
    for (i = 0; i <= deg2; i++)
    {
        printf("x^%d: ", i);
        scanf("%d", &b[i].coeff);
        b[i].exp = i;
    }
    printf("\nExpression 1 = \t\t\t%d", a[0].coeff);
    for (i = 1; i <= deg1; i++)
        printf(" + %dx^%d", a[i].coeff, a[i].exp);
    printf("\nExpression 2 = \t\t\t%d", b[0].coeff);
    for (i = 1; i <= deg2; i++)
        printf(" + %dx^%d", b[i].coeff, b[i].exp);
    if (deg1 > deg2)
    {
        for (i = 0; i <= deg2; i++)
        {
            c[i].coeff = a[i].coeff + b[i].coeff;
            c[i].exp = a[i].exp;
        }
        for (i = deg2 + 1; i <= deg1; i++)
        {
            c[i].coeff = a[i].coeff;
            c[i].exp = a[i].exp;
        }
    }
    else
    {
        for (i = 0; i <= deg1; i++)
        {
            c[i].coeff = a[i].coeff + b[i].coeff;
            c[i].exp = a[i].exp;
        }
        for (i = deg1 + 1; i <= deg2; i++)
        {
            c[i].coeff = b[i].coeff;
            c[i].exp = b[i].exp;
        }
    }
    printf("\nExpression after addition = \t%d", c[0].coeff);
    for (int j = 1; j < i; j++)
        printf(" + %dx^%d", c[j].coeff, c[j].exp);
}
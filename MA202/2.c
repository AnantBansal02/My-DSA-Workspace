#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, k;
    float a[10][10], l[10][10], u[10][10], b[10], y[10], x[10], sum;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter the elements of vector :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        // Upper triangular matrix
        for (j = i; j < n; j++)
        {
            sum = 0;
            for (k = 0; k < i; k++)
            {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
        }
        // Lower triangular matrix
        for (j = i; j < n; j++)
        {
            if (i == j)
            {
                l[i][i] = 1;
            }
            else
            {
                sum = 0;
                for (k = 0; k < i; k++)
                {
                    sum += l[j][k] * u[k][i];
                }
                l[j][i] = (a[j][i] - sum) / u[i][i];
            }
        }
    }
    printf("[Lower Triangular ]: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%9.3f ", l[i][j]);
        printf("\n");
    }
    printf("\n\n[Upper Triangular]: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%9.3f ", u[i][j]);
        printf("\n");
    }
    // Solve for y using forward substitution
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < i; j++)
        {
            sum += l[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / l[i][i];
    }
    printf("\n\n[Y]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%9.3f", y[i]);
        printf("\n");
    }
    // Solve for x using backward substitution
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= u[i][j] * x[j];
        }
        x[i] /= u[i][i];
    }
    printf("\n\n[X]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%9.3f", x[i]);
        printf("\n");
    }
}
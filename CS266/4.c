#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double solve(double ar[3][3], int i, int n)
{
    if (n == 2)
    {
        return ar[1][(i + 1) % 3] * ar[2][(i + 2) % 3] - ar[1][(i + 2) % 3] * ar[2][(i + 1) % 3];
    }
    return 0;
}
int main()
{
    int n = 3;
    double lambda;
    printf("Enter the value of lambda : ");
    scanf("%lf", &lambda);
    double ar[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter value at (%d,%d) : ", i, j);
            scanf("%lf", &ar[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ar[i][i] -= lambda;
    }
    double ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans += ar[0][i] * solve(ar, i, n - 1);
    }
    printf("The determinant of following matrix is : %lf", ans);
}
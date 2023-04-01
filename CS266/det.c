#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int solve(int ar[3][3], int i, int n)
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
    int ar[n][n];
    printf("Enter 3x3 Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans += ar[0][i] * solve(ar, i, n - 1);
    }
    printf("--------------------------------------\n");
    printf("The determinant of above matrix is : %d", ans);
}
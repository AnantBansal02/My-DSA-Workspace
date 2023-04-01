#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
double func(double a[3][3], double l)
{
    return (a[0][0] - l) * (((a[1][1] - l) * (a[2][2] - l)) - (a[2][1] *
                                                               a[1][2])) -
           a[0][1] * (a[1][0] * (a[2][2] - l) - a[2][0] * a[1][2]) +
           a[0][2] * (a[1][0] * a[2][1] - a[2][0] * (a[1][1] - l));
}
double Secant(double mat[3][3], double a, double b)
{
    double c = 0;
    while (func(mat, c) <= -0.0000001 || func(mat, c) >= 0.0000001)
    {
        c = b - ((func(mat, b) * (mat, b - a))) / (func(mat, b) -
                                                   func(mat, a));
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    double arr[3][3] = {{1, 0, 0}, {0, 0, 1}, {0, 1, 0}};
    double a1, a2;
    srand(time(0));
    double a = (double)rand() / RAND_MAX * 20 - 10;
    double b = (double)rand() / RAND_MAX * 20 - 10;
    a1 = Secant(arr, a, b);
    printf("Eigenvalues are: %lf, ", a1);
    a2 = Secant(arr, a, b);
    while (a1 == a2)
    {
        srand(time(0));
        a = (double)rand() / RAND_MAX * 20 - 10;
        b = (double)rand() / RAND_MAX * 20 - 10;
        a2 = Secant(arr, a, b);
    }
    printf("%lf", a2);
}
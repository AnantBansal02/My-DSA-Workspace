#include <stdio.h>
#include <math.h>
#define dt 0.01
#define N 100000
double sigma = 10.0;
double b = 8.0 / 3.0;
double r = 24.1;
double dxdt(double x, double y, double z)
{
    return sigma * (y - x);
}
double dydt(double x, double y, double z)
{
    return r * x - y - x * z;
}
double dzdt(double x, double y, double z)
{
    return -b * z + x * y;
}
int main()
{
    FILE * output = NULL;
    output = fopen("output.txt", "w");
    double x = 25.0, y = 18.0, z = 120.0;
    double k1x, k1y, k1z, k2x, k2y, k2z, k3x, k3y, k3z, k4x, k4y,k4z;
    int i;
    for (i = 0; i < N; i++)
    {
        k1x = dt * dxdt(x, y, z);
        k1y = dt * dydt(x, y, z);
        k1z = dt * dzdt(x, y, z);
        k2x = dt * dxdt(x + k1x / 2, y + k1y / 2, z + k1z / 2);
        k2y = dt * dydt(x + k1x / 2, y + k1y / 2, z + k1z / 2);
        k2z = dt * dzdt(x + k1x / 2, y + k1y / 2, z + k1z / 2);
        k3x = dt * dxdt(x + k2x / 2, y + k2y / 2, z + k2z / 2);
        k3y = dt * dydt(x + k2x / 2, y + k2y / 2, z + k2z / 2);
        k3z = dt * dzdt(x + k2x / 2, y + k2y / 2, z + k2z / 2);
        k4x = dt * dxdt(x + k3x, y + k3y, z + k3z);
        k4y = dt * dydt(x + k3x, y + k3y, z + k3z);
        k4z = dt * dzdt(x + k3x, y + k3y, z + k3z);
        x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;
        z += (k1z + 2 * k2z + 2 * k3z + k4z) / 6;
        fprintf(output,"%f,%f,%f\n", x, y, z);
    }
    return 0;
}
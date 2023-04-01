#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x - tan(x)
int main()
{
    double x;
    int lambda = 1;
    double y = lambda * x - tan(x);
    int root = 0;
    double roots[6];
    int flag = 0;
    int i = 0;
    while (i <= 999)
    {
        double a = i * 0.02 + 0;
        double b = a + 0.02;
        if (a == b)
        {
            continue;
        }
        double ya = f(a);
        double yb = f(b);
        double k;
        while (ya * yb <= 0)
        {
            ya = f(a);
            yb = f(b);
            double t = (a + b) / 2;
            if (fabs(ya * yb) > 100)
            {
                break;
            }
            if (fabs(a - b) <= 0.000001)
            {
                flag = 0;
                for (int i = 0; i < root; i++)
                {
                    if (round(roots[i]) == round(t))
                    {
                        flag++;
                        break;
                    }
                }
                if (flag == 0)
                {
                    roots[root] = t;
                    root++;
                    break;
                }
                else
                {
                    break;
                }
            }
            double yt = f(t);
            if (yt * ya <= 0)
            {
                b = t;
            }
            else if (yt * yb <= 0)
            {
                a = t;
            }
            k = t;
        }
        i++;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("Root number %d is : %0.7lf\n", i + 1, roots[i]);
    }
}
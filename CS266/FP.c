#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) (x - 4) * (x - 2) * (x + 3) * (x + 7)
int main()
{
    double x;
    double y = (x - 4) * (x - 2) * (x + 3) * (x + 7);
    int root = 0;
    double ans[4];
    int Time;
    int iterations = 0;
    printf("Enter the seeding time : ");
    scanf("%d", &Time);
    srand(Time);
    int flag = 0;
    while (root != 4)
    {
        double a = rand() % 50 - 25;
        double b = rand() % 50 - 25;
        if (a == b || (fabs(a) == fabs(b)))
        {
            continue;
        }
        double ya = f(a);
        double yb = f(b);
        double k;
        while (ya * yb < 0)
        {
            ya = f(a);
            yb = f(b);
            double t = (a * f(b) - b * f(a)) / (f(b) - f(a));
            if (a == t || b == t)
            {
                break;
            }
            iterations++;
            double yt = f(t);
            if (fabs(yt) <= 0.000001)
            {
                for (int i = 0; i < root; i++)
                {
                    if (round(ans[i]) == round(t))
                    {
                        flag++;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[root] = t;
                    root++;
                    break;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (fabs(t - k) <= 0.000001)
            {
                for (int i = 0; i < root; i++)
                {
                    if (round(ans[i]) == round(t))
                    {
                        flag++;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[root] = t;
                    root++;
                    break;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
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
    }
    printf("No of iterations = %d\n", iterations);
    for (int i = 0; i < 4; i++)
    {
        printf("Root number %d is : %0.7lf\n", i, ans[i]);
    }
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) (x - 4) * (x - 2) * (x + 3) * (x + 7)
int main()
{
    double x;
    double y = (x - 4) * (x - 2) * (x + 3) * (x + 7);
    int root = 0;
    double roots[4];
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
        double ya = f(a);
        double yb = f(b);
        if (a == b || (fabs(a) == fabs(b)) || ya * yb > 0)
        {
            continue;
        }
        while (root != 10)
        {
            ya = f(a);
            yb = f(b);
            double t = (a * f(b) - b * f(a)) / (f(b) - f(a));
            if (a == t || b == t || a == b)
            {
                break;
            }
            iterations++;
            double yt = f(t);
            if (fabs(yt) <= 0.000001)
            {
                for (int i = 0; i < root; i++)
                {
                    if (round(roots[i]) == round(t) || round(yt) != 0)
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
                    flag = 0;
                    break;
                }
            }
            if (fabs(a - b) <= 0.000001)
            {
                for (int i = 0; i < root; i++)
                {
                    if (round(roots[i]) == round(t) || round(yt) != 0)
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
                    flag = 0;
                    break;
                }
            }
            a = b;
            b = t;
        }
    }
    printf("No of iterations = %d\n", iterations);
    for (int i = 0; i < 4; i++)
    {
        printf("Root number %d is : %0.8lf\n", i, roots[i]);
    }
}
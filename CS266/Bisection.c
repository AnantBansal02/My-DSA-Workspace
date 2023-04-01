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
    int itr = 0;
    printf("Enter the seeding time : ");
    scanf("%d", &Time);
    srand(Time);
    while (root != 4)
    {
        double a = rand() % 50 - 25;
        double b = rand() % 50 - 25;
        if (a == b || (fabs(a) == fabs(b) && f(0.0) != 0))
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
            double t = (a + b) / 2;
            itr++;
            double yt = f(t);
            if (fabs(t - k) <= 0.000001)
            {
                int flag = 0;
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
    printf("No of itr = %d\n", itr);
    for (int i = 0; i < 4; i++)
    {
        printf("Root number %d is : %0.7lf\n", i + 1, ans[i]);
    }
}
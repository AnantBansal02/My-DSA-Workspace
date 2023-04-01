#include <stdio.h>
#include <math.h>
double tan_inverse(double x, int M)
{
    int i = 0;
    double ans = 0;
    while (i <= M)
    {
        ans += pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        // printf("%d and %0.15lf\n",i,ans);
        i++;
    }
    return ans;
}
int findM()
{
    int M = 0;
    double x = 1, val;
    val = 1;
    while (val >= pow(10, -5))
    {
        M++;
        val = pow(x, 2 * M + 3) / (2 * M + 3);
    }
    return M;
}
int main()
{
    double x;
    printf("Enter any value of x in domain [0,1] : ");
    scanf("%lf", &x);
    int M = findM(); // function to find value of M s.t. error is less than 10^-5
    printf("The value of M s.t. the error is less than 10^-5 is : %d\n", M);
    double val = tan_inverse(x, M);                 // function to calaculte tan^-1(x) value using expansion
    double error = pow(x, 2 * M + 3) / (2 * M + 3); // calculating the net error in the value
    double ans = val + error;                       // adding the ans from expansion and the error
    printf("The value of tan^-1(x) in domain [0,1] is %0.10lf", ans);
    // Calculating value of pi
    val = tan_inverse(1, M);
    error = pow(1, 2 * M + 3) / (2 * M + 3);
    ans = val + error;
    double pi = ans * 4;
    printf("\nThe value of pi is = %0.10lf error is %0.10lf", pi, error);
    return 0;
}
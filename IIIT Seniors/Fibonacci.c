#include<stdio.h>

int main()
{
    int a = 0;
    int b = 1;
    printf("%d %d ",a,b);
    int c;
    while(a+b<=100)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%d ",c);
    }
    return 0;
}
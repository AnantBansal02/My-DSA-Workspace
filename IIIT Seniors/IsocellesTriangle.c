#include<stdio.h>

int main()
{
    int n;
    printf("Enter the no of rows:  ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>i;j--)
        {
            printf(" ");
        }
        for(int a=1;a<=i;a++)
        {
            printf("* ");
        }
        printf("\n");
    }
} 
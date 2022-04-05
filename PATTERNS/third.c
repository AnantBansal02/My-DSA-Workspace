#include<stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int pattern[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i<=1 || j==0 || j==i)
            {pattern[i][j] = 1;}
            else{pattern[i][j] = pattern[i-1][j] + pattern[i-1][j-1];}
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d ",pattern[i][j]);
        }
        printf("\n");
    }
    return 0;
}
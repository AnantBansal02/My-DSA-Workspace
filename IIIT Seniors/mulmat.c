#include<stdio.h>

int main()
{
    int p,q,r,s;
    printf("Enter dimensions of the First matrix : ");
    scanf("%d %d",&p,&q);
    printf("Enter dimensions of the Second matrix : ");
    scanf("%d %d",&r,&s);
    if(q!=r){printf("Multiplication is not Possible !!!");return 0;}
    int a[p][q];
    int b[r][s];
    printf("\nInput First Matrix : \n");
    for(int i=0;i<p;i++)
    {
        printf("Input %d row : ",i+1);
        for(int j=0;j<q;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nInput Second Matrix : \n");
    for(int i=0;i<r;i++)
    {
        printf("Input %d row : ",i+1);
        for(int j=0;j<s;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    
    int ans[p][s];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<s;j++)
        {
           ans[i][j]=0;    
           for(int k=0;k<q;k++)    
            {    
                ans[i][j]+=a[i][k]*b[k][j];    
            }
        }
    }
    printf("\nMultiplication Matrix : \n");
    for(int i=0;i<p;i++)
    {
        printf("Output %d row : ",i+1);
        for(int j=0;j<s;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
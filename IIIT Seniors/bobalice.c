#include<stdio.h>

int main()
{
    int n,a;
    printf("Program for Bob ->\nEnter the number of toys for Bob : ");
    scanf("%d",&n);
    printf("Enter the numbers : ");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    printf("Output : ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n\nProgram for Alice ->\nEnter the number of toys for Alice : ");
    scanf("%d",&a);
    printf("Enter the numbers : ");
    int arr2[a];
    for(int i=0;i<a;i++)
    {
        scanf("%d",&arr2[i]);
    }
    for(int i=0;i<a-1;i++)
    {
        for(int j=i+1;j<a;j++)
        {
            if(arr2[i]<arr2[j])
            {
                int temp = arr2[j];
                arr2[j]=arr2[i];
                arr2[i]=temp;
            }
        }
    }
    printf("Output : ");
    for(int i=0;i<a;i++)
    {
        printf("%d,",arr2[i]);
    }
    return 0;
}
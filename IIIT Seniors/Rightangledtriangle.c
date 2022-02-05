/*problem1.) C program to print stars Sequences for right angular triangle.   
Program made by ANANT BANSAL on 5/02/22 SID:202151021*/   
#include<stdio.h>   

int main()   
{   
    int n;      
    printf("Enter the number of rows:  ");  
    scanf("%d",&n);    
    for(int i=1;i<=n;i++)   
    { 
        for(int j=1;j<=i;j++)   
        {    
            printf("* ");   
        }   
        printf("\n");   
    }   
    return 0;   
} 
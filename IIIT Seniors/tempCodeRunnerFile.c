/*problem3.) C program to find greatest in 3 numbers using nested if 
Program made by ANANT BANSAL on 21/01/22 SID:202151021*/

#include<stdio.h>

int main()
{
    int a,b,c;
    printf("Enter three different integers:\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    {
        if(a>c){printf("%d is the greatest integer.\n",a);}
        else{printf("%d is the greatest integer.\n",c);}
    }
    
    else
    {
        if(b>c){printf("%d is the greatest integer.\n",b);}
        else{printf("%d is the greatest integer.\n",c);}
    }
    return 0;
}
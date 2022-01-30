//Problem 1: Ramesh's basic salary is input through keyboard. His dearness allowance is 40%
//of basic salary and house rent allowance is 20% of his basic salary. Write an algorithm, Flowchart and 
// program to calculate his gross salary.

//Program made by Anant Bansal SID:202151021
#include<stdio.h>
int main()
{
    float a;
    scanf("%f",&a);
    float b =  0.4*a;
    float c= 0.2*a;
    a= a+ 0.6*a;
    printf("Dearness Allowance = %0.1f\n",b);
    printf("Rent Allowance = %0.01f\n",c);
    printf("Gross Salary = %0.1f",a);
    return 0; 
}
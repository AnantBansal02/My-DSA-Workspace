//  returnType functionName (parameter1,parameter2,...){body} 
// EG: add two numbers:

# include<iostream>
using namespace std;
int add(int num1,int num2){
    int sum= num1 + num2;
    return sum;
}


int main()
{
    int a=2,b=3;
    cout<<add(a,b)<<endl;
    return 0;
} 
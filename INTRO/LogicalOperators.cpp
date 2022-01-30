#include<iostream>
using namespace std;

int main()
{
// {&& And operator if both operands are true}
// || Or operator
// ! Not operator
// == equal operator
// != Not equal operator
int n;
cin>>n;
if(n%3==0 && n%2==0)
{cout<<"Divisible by both 2 and 3";}
else if(n%3==0){cout<<"Divisible only by 3";}
else if (n%2==0){cout<<"Divisible only by 2";}
else{cout<<"Divisible by none";}
return 0;
}
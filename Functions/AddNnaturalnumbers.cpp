#include<iostream>
using namespace std;

int sum(int num)
{
    int a=num*(num+1)/2;
    return a;
}

int main()
{
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int factorial(int num)
{
    int ans=1;
    for(int i=1;i<=num;i++)
    {
        ans=ans*i;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {cout<<factorial(i)/(factorial(j)*factorial(i-j))<<" ";}
        cout<<endl;
    }

    return 0;
}
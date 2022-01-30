#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int reverse=0;
    while(n>0)
    {
        int last= n%10;
        reverse = reverse*10 + last;
        n=n/10;
    }

    cout<<reverse<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int a=0,b=1,n;
    cin>>n;
    cout<<a<<endl<<b<<endl;
    for(int i=1;i<=(n-2);i++)
    {
        cout<<a+b<<endl;
        int c=b;
        b=a+b;
        a=c;
    }
    return 0;
}

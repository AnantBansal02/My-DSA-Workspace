#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int a;
        for(a=2;a<=i;a++)
        {
            if(i%a==0){break;}
        }
        if(a==i){cout<<i<<endl;}
    }
    return 0; 
}
//Binary to Decimal;
#include<iostream>
using namespace std;

int conv(int num)
{
    int ans=0;
    int y=1;
    while(num>0)
    {
        int x=num%10;
        ans+=x*y;
        y=2*y;
        num/=10;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<conv(n)<<endl;
    return 0;
}
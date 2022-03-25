#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n = a.length();
    int space = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout<<" ";
        }
        if(i==1)
        {cout<<a[0]<<endl;}
        if(i>=2)
        {
        cout<<a[i-1];
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        cout<<a[i-1];
        cout<<endl;
        space += 2;
        }
    }
    string b = a;
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - i - 1]);
    }
    cout<<a;
    for(int i=1;i<n;i++)
    {
        cout<<b[i];
    }
    return 0;
}

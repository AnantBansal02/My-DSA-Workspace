#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,r,s;
    cout<<"Dimensions of First Matrix : "; 
    cin>>p>>q;
    cout<<"Dimensions of Second Matrix : "; 
    cin>>r>>s;
    if(q!=r){cout<<"Multiplication is not Possible!!!";return 0;}
    int a[p][q];
    int b[r][s];
    cout<<"Input First Matrix :"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<"Input "<<i+1<<" Row : ";
        for(int j=0;j<q;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Input Second Matrix :"<<endl;
    for(int i=0;i<r;i++)
    {
        cout<<"Input "<<i+1<<" Row : ";
        for(int j=0;j<s;j++)
        {
            cin>>b[i][j];
        }
    }
    int ans[p][s];
    cout<<"Multiplied Matrix : "<<endl;;
    for(int i=0;i<p;i++)
    {
        cout<<"Output "<<i+1<<" Row : ";
        for(int j=0;j<s;j++)
        {
            ans[i][j] = 0;
            for(int k=0;k<q;k++)
            {
                ans[i][j] += a[i][k]*b[k][j];
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
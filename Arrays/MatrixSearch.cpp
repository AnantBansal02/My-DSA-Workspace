#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter Dimensions : ";
    cin>>n>>m;
    int a[n][m];
    cout<<"Input Matrix : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int x;
    cout<<"Enter Target : ";
    cin>>x;
    int i=0,j=m-1;
    while(a[i][j]!=x)
    {
        if(a[i][j]>x){j--;}
        else{i++;}
        if(j<0 || i<0 || j>m || i>n){cout<<"Not Found!!!";return 0;}
    }
    cout<<i+1<<" "<<j+1<<endl;
    return 0;
}
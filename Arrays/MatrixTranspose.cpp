#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q;
    cin>>p>>q;
    int arr[p][q];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans[q][p];
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<p;j++)
        {
            ans[i][j] = arr[j][i];
        }
    }
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<p;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        for(int j=i;j<n;j++)
        {
            //swap
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
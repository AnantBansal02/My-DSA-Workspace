#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //cout<<"Enter i till which max is to be found"<<endl;
    int mx = -999999999;
    for(int a=0;a<n;a++)
    {
        mx = max(mx,arr[a]);
        cout<<"max till "<<a<<" = "<<mx<<endl;
    }
    
    return 0;
}
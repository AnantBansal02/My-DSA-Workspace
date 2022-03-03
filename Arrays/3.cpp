#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    bool b[mx+2];
    for(int i=0;i<mx+2;i++)
    {
        b[i] = false;
    }
    for(int i=0;i<n;i++)
    {
       if(a[i]>0){b[a[i]] = true;}
       else{continue;}
    }
    for(int i=1;i<mx+2;i++)
    {
        if(b[i]==false)
        {
            cout<<i<<endl;
            return 0;
        }
        else{continue;}
    }
    return 0;
}
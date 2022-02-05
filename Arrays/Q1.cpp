// Nested for loop {increased time complexity!!!}
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int ans = INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if ( a[i] == a[j] && j!=0){ans = min(ans,j);}

//         }
//     }
//     if(ans == INT_MAX){cout<<"No repitition!!!";}
//     if(ans != INT_MAX){cout<<"Smallest Index of repeating unit = "<<ans+1<<endl;}
// }
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int mx = INT_MIN;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    int idx[mx];
    for(int i=0;i<mx;i++)
    {
        idx[i] = -1;
    }
    int minidx = INT_MAX;
    for(int i=0 ; i<n ;i++)
    {
        if(idx[a[i]] != -1)
        {
            minidx = min (minidx, idx[a[i]]);
        }       
        else
        {
            idx[a[i]] = i;
        }
    }
    if(minidx == INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<minidx+1<<endl;
    }

    
    return 0;
}
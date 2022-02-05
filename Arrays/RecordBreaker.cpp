// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int z;
//     cin>>z;
//     int x=1;
//     int b[z];
//     while(x<=z){
//     int n;
//     int counter=0;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     if(a[0]>a[1]){counter++;}
//     int c = INT_MIN;
//     for(int i=0;i<n-2;i++)
//     {
//         c = max(c,a[i]);
//         if(a[i+1]> c && a[i+1]>a[i+2]){counter++;}
//     }
//     if(a[n-2]>c && a[n-2]>a[n-1]){counter++;}
//     if(a[n-1]>c && a[n-1]>a[n-2]){counter++;}
//     b[x-1]=counter;
//     x++;}
//     for(int i=0;i<z;i++)
//     {
//         cout<<"Case #"<<i+1<<": "<<b[i]<<endl;
//     }
    
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    a[n] = -1;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;
    for(int i=0; i < n; i++)
    {
        if(a[i]>mx && a[i]>a[i+1])
        {
            ans++;
        }
        mx = max(mx,a[i]);
    }
    cout<<ans<<endl;
   
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     bool flag = 0;
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(k == a[i]+a[j]){
//                 cout<<"True"<<endl;
//                 bool flag = 1;
//                 return 0;
//             }
//         }
//     }
//     cout<<"False"<<endl;
//     return 0;
// }
/* Above method is brute force checking all pairs
time complexity O[n^2]*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]+a[i+1]
    }
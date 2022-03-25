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
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    int low = 0;
    int high = n-1;
    while(low<high){
        if(a[low]+a[high] == k){cout<<low<<" "<<high<<endl;return 0;}
        else if(a[low]+a[high] > k){high--;}
        else if(a[low]+a[high] < k){low++;}
    }
    cout<<"-1"<<endl;
    return 0;
}
// This program is intended for sorted arrays!!!
/**********
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , sum=0 , maxsum = INT_MIN;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                // cout<<a[k]<<" ";
                sum += a[k];
            }
            maxsum = max(maxsum, sum);
            sum = 0;
            // cout<<endl;
        }

    }
    cout<<"Max sum = "<<maxsum<<endl;
    return 0;
}
*///////////////////////


//  Very bad time complexity for finding maxsum in above problem!
// cumulative sum ko store karenge ek new array me
// isko kehte h cumulative sum approach
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int currsum[n+1];
    currsum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        currsum[i] = currsum[i-1] + a[i-1];
    }
    int maxsum = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int sum = 0;
        for(int j=0;j<i;j++)
        {
            sum = currsum[i] - currsum[j];
            maxsum = max(sum,maxsum);
        }
    }
    cout<<maxsum<<endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;


// int kadane(int arr[],int n){
//     int max_sum=0,max_end=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<=(max_end+arr[i])){
//             max_end+=arr[i];
//         }
//         else{
//             max_end=arr[i];
//         }
//         if(max_end>max_sum){
//             max_sum=max_end;
//         }
//     }
//     return max_sum;
// }


// int main(){
   
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<kadane(arr,n);
//     return 0;
// }
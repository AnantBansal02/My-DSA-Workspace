#include<bits/stdc++.h>
using namespace std;


void shuffle(int arr[], int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        int swap_idx = rand()%n;
        swap(arr[i],arr[swap_idx]);
    }

};
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    shuffle(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
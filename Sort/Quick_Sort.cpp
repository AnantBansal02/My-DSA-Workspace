#include<iostream>
using namespace std;

swap(int *a,int *b){
    int *temp = a;
    a = b;
    b = temp;
}
int partition(int arr[],int l,int h){
    int x = arr[h];
    int i = l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void QuickSort(int arr[],int l,int h){
    if(l<h){
        int pi = partition(arr,l,h);
        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,h);
    }
}
int main(){
    int a[] = {23,42,13,45,27,4,52,24,89};
    QuickSort(a,0,8);
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}
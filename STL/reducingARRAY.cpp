#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

bool MyCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first<p2.first;
    /*that's the comparator function...it's exactly same as when you write the code
    of bubble sort or any swap-based sorting algorithm then you have to put an 
    if condition like(arr[i]>arr[j]) then only swap...
    exactly here in the inbuilt sort function you can pass that 
    condition as in the form of comparator function... 
    so if your comparator function (in this case mycompare) returns false 
    then it will swap the values accordingly and eventually you will get your array sorted desirely...*/
    // pehle p1 mila fir p2 mila usko aise hi rehne de ya swap kre???
    // agr true aata h to aise hi rehne do vrna false pe swap krdo!
}
int main(){
    int arr[] = {10,16,7,14,5,3,12,9};
    vector < pair<int, int> > v;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(), MyCompare);
    for(int i=0;i<v.size();i++){
        arr[v[i].second] = i;
    }
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}
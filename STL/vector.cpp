#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    cout<<"Size : "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x); //O(1)
    //     printVector(v);
    // }
    // vector<int> v1(5 , 1); // 5 size ka vector with each value 1;
    // printVector(v1);
    // v1.push_back(5);// Continuous memory allocation
    // printVector(v1);
    // v1.pop_back();// Deallocation !!
    // printVector(v1);
    // vector<int> &v2 = v1; // Can directly copy vectors O(n) time com!!!
    // // When we pass a vector to a function copy vector is passed so O(n)
    // // So pass reference!!
    // printVector(v2);
    vector<string> v3(5);
    int n;
    cin>>n;
    return 0;
}
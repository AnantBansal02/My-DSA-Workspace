#include<bits/stdc++.h>
using namespace std;
void printv(vector<int> temp){
    for(auto it:temp){
        cout<<it<<" ";
    }
    cout<<endl;
}
void printsubseq(vector<int> arr, vector<int> &ans, int i){
    if(i==arr.size()){
        printv(ans);
        return;
    }
    ans.push_back(arr[i]);
    printsubseq(arr,ans,i+1);
    ans.pop_back();
    printsubseq(arr,ans,i+1);    
    
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<int> ans;
    int  i = 0;
    printsubseq(arr,ans,i);
}
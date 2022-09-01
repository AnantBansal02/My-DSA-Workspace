#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> ans;
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(),nums.end());
    do {
        ans.push_back(nums);
    }
    while(next_permutation(nums.begin(),nums.end()));
    for(auto v : ans){
        for(auto i : v)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
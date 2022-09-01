#include<bits/stdc++.h>
#include<deque>
using namespace std;

// Print maximum of each window given of a fixed size;

int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a){
        cin>>i;
    }
    /*
    multiset<int,greater<int>> s;
    vector<int> ans;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for(int i=k;i<n;i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;
    */
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!dq.empty() and a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);
    for(int i=k;i<n;i++){
        if(dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() and a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl; 

    return 0;
}
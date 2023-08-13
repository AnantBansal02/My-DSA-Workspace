#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {40,60,80};
    int idx = upper_bound(arr.begin(), arr.end(), 40) - arr.begin();
    cout<<idx<<"\n";
}
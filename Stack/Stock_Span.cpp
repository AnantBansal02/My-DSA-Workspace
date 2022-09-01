#include<bits/stdc++.h>
using namespace std;

vector<int> stock_span(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int>> st;
    for(int i=0;i<prices.size();i++){
        int days = 1;
        while(!st.empty() and st.top().first <= prices[i]){
            days += st.top().second;
            st.pop();
        }
        st.push({prices[i],days});
        ans.push_back(days);
    }
    return ans;
}
int main(){
    vector<int> a = {100,80,60,70,60,75,85};
    vector<int> res = stock_span(a);
    for(auto i:res){
        cout<<i<<" ";
    }cout<<"\n";
    return 0;
}
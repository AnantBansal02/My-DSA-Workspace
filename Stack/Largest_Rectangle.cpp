#include<bits/stdc++.h>
using namespace std;

int get_max_area(vector<int> a){
    int n = a.size();
    int ans = 0, i = 0;
    stack<int> st;
    st.push(0);
    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty()){
                ans = max(ans,h*i);
            }
            else{
                int l = i - st.top() - 1;
                ans = max(ans,h*l);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
int main(){
    vector<int> a = {2,1,5,6,5,3};
    cout<<get_max_area(a);
    return 0;
}
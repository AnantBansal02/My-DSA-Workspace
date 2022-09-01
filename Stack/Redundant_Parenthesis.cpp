#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    stack<char> st;
    bool ans = false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' or s[i] =='-' or s[i]=='*' or s[i] =='/'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top()=='('){
                ans = true;
                st.pop();
                break;
            }
            if(st.empty()){
                ans = true;
                break;
            }
            while(st.top()=='+' or st.top() =='-' or st.top()=='*' or st.top() =='/'){
                st.pop();
                if(st.empty()){
                    ans = true;
                    break;
                }
            }
            st.pop();
            if(ans){
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
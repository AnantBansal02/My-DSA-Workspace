#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    int n = s.size();
    stack <char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(!st.empty() and s[i]==')'){
            if(st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(!st.empty() and s[i]=='}'){
            if(st.top() == '{'){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(!st.empty() and s[i]==']'){
            if(st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}
int main(){
    string s = "{([])}";
    if(isValid(s)){
        cout<<"Valid String"<<endl;
    }
    else{
        cout<<"Invalid String"<<endl;
    }
    return 0;
}
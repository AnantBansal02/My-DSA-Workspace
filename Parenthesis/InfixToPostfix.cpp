#include<iostream>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c =='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string reverseString(string &s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        int temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    return s;
}
string InfPre(string s){
    stack<char> st;
    string res;
    reverseString(s);
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&&s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }

        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return reverseString(res);
}
string InfPost(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&&s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }

        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s = "((A+B)*(C*D-)*F/G)";
    s = "A*(B+C)/D"; 
    cout<<InfPost(s)<<endl;
    // cout<<InfPre(s)<<endl;
}
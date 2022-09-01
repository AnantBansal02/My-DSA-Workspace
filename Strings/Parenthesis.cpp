#include<iostream>
#include<stack>
using namespace std;
stack<int> st;
void brackets(string s){
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(i);
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            cout<<st.top()<<" "<<i<<endl;
            st.pop();
        }
    }
}
int main(){
    string s;
    cin>>s;
    brackets(s);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void reverse(string s,int n,int i){
    if(i==n){
        return;
    }
    reverse(s,n,i+1);
    cout<<s[i];
}
int main(){
    string s;
    cin>>s;
    int n = s.length();
    reverse(s,n,0);
    return 0;
}
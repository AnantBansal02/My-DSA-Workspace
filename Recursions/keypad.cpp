#include<bits/stdc++.h>
using namespace std;
void keypad(string s1,string s2){
    if(s2.length() == 0){
        return;
    }
    char ch2 = s2[0];
    for(int i=0;i<s1.length();i++){
        char ch1 = s1[i];
        cout<<ch1<<ch2<<endl;
    }
    keypad(s1,s2.substr(1));
}
int main(){
    string arr[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int a,b;
    cin>>a>>b;
    string s1 = arr[a];
    string s2 = arr[b];
    keypad(s1,s2);
    return 0;
}
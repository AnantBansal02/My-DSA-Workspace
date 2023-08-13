#include<bits/stdc++.h>
using namespace std;
struct Leaf{
    int length;
    string s;
    Leaf(){
        length = 0;
        s = "";
    }
    Leaf(int val, string a){
        length = val;
        s = a;
    }
};

struct Internal{
    int length;
    Internal *lefti,*righti;
    Leaf *leftl,*rightl;
    Internal(){
        length = 0;
        lefti = NULL;
        righti = NULL;
        leftl = NULL;
        rightl = NULL;
    }
    Internal(int val){
        length = val;
        lefti = NULL;
        righti = NULL;
        leftl = NULL;
        rightl = NULL;
    }
};

void solve(int n, Internal *root){
    if(root->leftl and root->rightl){
        int x = root->leftl->length;
        if(n <= x){
            cout<<root->leftl->s[n-1];
        }
        else{
            cout<<root->rightl->s[n-x-1];
        }
        return;
    }
    else if(root->leftl and !root->rightl){
        int x = root->leftl->length;
        if(n <= x){
            cout<<root->leftl->s[n-1];
            return;
        }
        else{
            solve(n-x,root->righti);
            return;
        }
    }
    else if(!root->leftl and root->rightl){
        int x = root->lefti->length;
        if(n > x){
            cout<<root->rightl->s[n-x-1];
            return;
        }
        else{
            solve(n,root->lefti);
            return;
        }
    }
    else{
        int x = root->lefti->length;
        if(n <=x ){
            solve(n,root->lefti);
            return;
        }
        else{
            solve(n-x,root->righti);
            return;
        }
    }
}
int main(){
    Internal *root = new Internal(10);
    Internal *Root = root;
    root->lefti = new Internal(7);
    root->righti = new Internal(3);
    Internal *temp = root;
    temp = temp->lefti;
    temp->rightl = new Leaf(3,"EFG");
    temp->lefti = new Internal(4);
    temp = temp->lefti;
    temp->leftl = new Leaf(1,"A");
    temp->rightl = new Leaf(3,"BCD");
    root = root->righti;
    root->leftl = new Leaf(2,"PQ");
    root->rightl = new Leaf(1,"Z");
    int n;cin>>n;
    solve(n,Root);
}
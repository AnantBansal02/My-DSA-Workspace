#include<iostream>
using namespace std;

class Hero{
    public:
    int val;
    Hero(){
        cout<<"Constructor Called"<<"\n";
    }
    void setVal(int a){
        val = a;
    }
};

int main(){
    Hero a;
    Hero *b = &a;
    a.val = 24;
    cout<<a.val<<"\n";
    b->val = 34;
    cout<<a.val<<"\n";
}
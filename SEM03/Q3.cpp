#include<iostream>
using namespace std;

#define int long long

class student{
    public:
    string name;
    student(){
        cout<<"Unknown"<<endl;
    }
    student(string s){
        name = s;
        cout<<s<<", Welcome to IIITV"<<endl;
    }
};

signed main(){
    student();
    student("Anant");
    return 0;
}
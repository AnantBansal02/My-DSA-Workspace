#include<bits/stdc++.h>
using namespace std;

int main(){
    // pair<int,string> p;
    // p = make_pair(5,"Anant");
    // p = {21,"Bansal"};
    // cout<<p.first<<endl;
    // cout<<p.second<<endl;
    // // pair<int,string> &p1 = p;// by reference
    // pair<int,string> p1 = p;// by copy variable

    // p1.first = 25;
    // cout<<p.first;

    // Usage is to pair the variables in array
    pair<int,int> p_array[3];
    p_array[0]={1,2};
    p_array[1]={3,4};
    p_array[2]={5,6};
    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    return 0;
}
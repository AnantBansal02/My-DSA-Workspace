#include<iostream>
#include<cmath>
using namespace std;

bool py(int n1,int n2,int n3)
{
    if(pow(n1,2)==pow(n2,2)+pow(n3,2)){return true;}
    else if(pow(n2,2)==pow(n1,2)+pow(n3,2)){return true;}
    else if(pow(n3,2)==pow(n2,2)+pow(n1,2)){return true;}
    else{return false;}
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(py(a,b,c)){cout<<"Pythogorean Triplet";}
    else{cout<<"Not a Pythogorean Triplet";}
    return 0;
}
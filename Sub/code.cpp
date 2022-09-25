#include<iostream>
using LL = long long;
using namespace std;
LL fact(LL x){
if(x==0){
return 1;
}
LL ans = fact(x-1);
return ans*x;
}
LL power(LL n,LL p){
if(p==0)
{
return 1;
}
LL prevans = power(n,p-1);
return n*prevans;
}
int main(){
cout<<"Please enter number of objects in urn ";
LL n;
cin>>n;
LL k;
cout<<"Please enter number of objects to be chosen from urn ";
cin>>k;
cout<<endl;
cout<<"OUTPUT : "<<endl;
cout<<endl;
cout<<"Permutations with replacement : ";
cout<<power(n,k)<<endl;
cout<<"Permutations without replacement : ";
cout<<fact(n)/fact(n-k)<<endl;
cout<<"Combinations with replacement : ";
cout<<fact(k+n-1)/(fact(n-1)*fact(k))<<endl;
cout<<"Combinations without replacement : ";
cout<<fact(n)/(fact(n-k)*fact(k))<<endl;
return 0;
}
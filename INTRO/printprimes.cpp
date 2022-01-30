#include<iostream>
using namespace std;

int main()
{
   int b;
   cin>>b;

   for(int num=2;num<=b;num++)
      {   int i;
          for(i=2;i<num;i++){
          if(num%i==0){
              break;
          }
          }if(i==num){
              cout<<num<<endl;
          }
      }
    return 0;
} 
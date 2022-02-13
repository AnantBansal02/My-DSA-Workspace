// #include <stdio.h>
// int main()
// {
//     int a,b;
//     printf("Input Two Numbers!");
//     scanf("%d",&a);
//     scanf("%d",&b);
//     int c=a+b;
//     printf("Addition Sum = %d",c);
//     return 0;
// }
#include<iostream>
#include<string>
using namespace std;


int main(){
    string s="vadodara";
    string ros;
    
    for(int i=0;i<s.size();i+=3){
        
    
       
       if((i+2)==s.size()){
          ros=ros+s[i+1]+s[i];
       }
       else{
            ros=ros+s[i+2]+s[i+1]+s[i];
       }
    
   
       
    }
    char arr[26];
    arr[0]='a';
    int i;
    for( i=1;i<26;i++){
        arr[i]='a'+i;

    }
    string ros2;
    for(int w=0;w<ros.size();w++){
      for(int r=0;r<26;r++){
        if(ros[w]==arr[r]){
            ros2[w]=arr[25-r];
        }
    }  
    }
    int count=0;
    int a,b;
   cin>>a>>b;
   int c,d;
   while(d>c){
       for(int u=0;u<26;u++){
           for(c=a;c<=b;c++){
           if(ros2[c]==arr[u]{
               if(u>)
           })
       }
       
       }
   }
    
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==0)
    {
        return 0;
    }
    int prevsum = sum(n-1);
    return (n+prevsum);
}

int power(int n,int p){
    if(p==0)
    {
        return 1;
    }
    int prevans = power(n,p-1);
    return n*prevans;
}

int fact(int n){
    if(n==0)
    {
        return 1;
    }
    int prevans = fact(n-1);
    return (n*prevans);
}

int fib(int n){
    // nth fibonacci number!
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int prevans = fib(n-1)+fib(n-2);
    return prevans;
}


int main(){

    return 0;
}
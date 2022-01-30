#include<bits/stdc++.h>
using namespace std;

int add( int a, int b)
{
    int ans = 0;
    int prevcarry = 0;
    while( a>0 && b>0)
    {
        if( a%2 == 0 && b%2 == 0 )
        {
            ans = ans*10 + prevcarry;
            prevcarry = 0;
        }
        else if((a%2==0 && b%2==1)||(a%2==1 && b%2==0))
        {
            if(prevcarry==1)
            {
                ans = ans*10 + 0;
                prevcarry = 1;
            }
            else
            {
                ans = ans*10 +1;
                prevcarry = 0;
            }

        }
        else if(a%2==1 && b%2==1)
        {
            ans = ans*10 + prevcarry;
            prevcarry = 1;
        }
        a /= 10;
        b /=10;
    }
    while(a>0)
    {
        if(prevcarry == 1)
        {
            if(a%2 == 1)
            {
                ans = ans*10 +0;
                prevcarry = 1;
            }
            else
            {
                ans = ans*10 + 1;
                prevcarry = 0;
            }
        }
        else
        {
             if(a%2 == 1)
            {
                ans = ans*10 +1;
                prevcarry = 0;
            }
            else
            {
                ans = ans*10 + 0;
                prevcarry = 0;
            }
        }
        a /= 10;
    }
     while(b>0)
    {
        if(prevcarry == 1)
        {
            if(b%2 == 1)
            {
                ans = ans*10 +0;
                prevcarry = 1;
            }
            else
            {
                ans = ans*10 + 1;
                prevcarry = 0;
            }
        }
        else
        {
             if(b%2 == 1)
            {
                ans = ans*10 +1;
                prevcarry = 0;
            }
            else
            {
                ans = ans*10 + 0;
                prevcarry = 0;
            }
        }
        b /= 10;
    }
    if(prevcarry == 1)
    {
        ans = ans*10 + 1;
    }
    int ansr = 0;
    while(ans>0)
    {
        int x = ans%10;
        ansr = ansr*10 + x;
        ans /= 10;
    }
    return ansr;
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << add(a,b)<< endl;
    return 0;
}
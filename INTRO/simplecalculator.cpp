#include<iostream>
using namespace std;

int main()
{
    float a,b;
    cout<<"Enter two numbers";
    cin>>a>>b;

    char op;
    cout<<"Input a operator"<<endl;
    cin>>op;

    switch (op)
    {
    case '+':
      cout<<a+b;
        break;

        case '-':
      cout<<a-b;
        break;

        case '*':
      cout<<a*b;
        break;

        case '/':
      cout<<a/b;
        break;

    default:
    cout<<"Please input a valid operator!";
        break;
    }
    return 0;
}

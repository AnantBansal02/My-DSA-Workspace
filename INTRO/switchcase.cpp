#include<iostream>
using namespace std;

int main()
{   char i;
    cin>>i;
    switch (i)
    {
      case 'a':
        cout<<"Hello";
        break;

      case 'b':
       cout<<"Namaste";
       break;

      case 'c':
       cout<<"Hola";
       break;

      default:
      cout<<"I am still learning more!";
        break;
    }
    return 0;
}
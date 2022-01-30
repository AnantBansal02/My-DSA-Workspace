#include<iostream>
using namespace std;

int main()
{
    int i=2;
    int j=3;
    // 2 + 4 + 3 + 3 + 5 + 4 = 21 i=4 j=5
    int k = i++ + ++i + j + j++ + ++j + i;
    cout<< i << j << k;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void rightRotateByOne(int A[], int n)
{
    int last = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        A[i + 1] = A[i];
    }
 
    A[0] = last;
}
void rightRotate(int A[], int k, int n)
{
    if (k < 0 || k >= n) {
        return;
    }
 
    for (int i = 0; i < k; i++) {
        rightRotateByOne(A, n);
    }
}

int main(void)
{
    
    int a,k,q;
    cin>>a>>k>>q;
    int A[a];
    for(int i=0;i<a;i++)
    {
        cin>>A[i];
    }

    int n = sizeof(A)/sizeof(A[0]);
 
    rightRotate(A, k, n);
    int answer[q];
    for(int i=0;i<q;i++)
    {
        int g;
        cin>>g;
        answer[i] = A[g];
    }
    for(int i=0;i<q;i++)
    {
        cout<<answer[i];
        cout<<endl;
    }
    return 0;
}
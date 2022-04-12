#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr1[n];
	int arr2[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
		cin>>arr2[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=arr1[i];j++)
		{
			for(int k=1;k<=(2*arr2[i] +1+arr2[i]);k++)
			{
				cout<<"*";
			}
            cout<<endl;
            cout<<"*";
            for(int k=1;k<=arr2[i];k++)
            {
                cout<<"..*";
            }
            cout<<endl;
            cout<<"*";
            for(int k=1;k<=arr2[i];k++)
            {
                cout<<"..*";
            }
            cout<<endl;
		}
        for(int k=1;k<=(2*arr2[i] +1+arr2[i]);k++)
		{
			cout<<"*";
		}
        cout<<endl<<endl;
        
	}
	return 0;
}
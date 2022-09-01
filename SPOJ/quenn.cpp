#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t>0){
	    int n,x,y;
	    cin>>n>>x>>y;
	    int ans = 0;
	    ans = 2*n -2;
	    int a = x,b = y;
	    while(a<=n && b<=n){
	        a++;
	        b++;
	        if(a<=n && b<=n){
	            ans++;
	        }
	    }
	    a =x;b =y;
	    while(a<=n && b>=1){
	        a++;
	        b--;
	        if(a<=n && b>=1){
	            ans++;
	        }
	    }
	    a =x;b =y;
	    while(a>=1 && b>=1){
	        a--;
	        b--;
	        if(a>=1 && b>=1){
	            ans++;
	        }
	    }
	    a =x;b =y;
	    while(a>=1 && b<=n){
	        a--;
	        b++;
	        if(a<=n && b>=1){
	            ans++;
	        }
	    }
	    cout<<ans-1<<endl;
	    t--;
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int> adj[k];
        for(int i=0;i<N-1;i++){
            string a = dict[i];
            string b = dict[i+1];
            int n = min(a.size(),b.size());
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    adj[a[i]-'a'].push_back(b[i]-'a');
                    break;
                }
            }
        }
        vector<int> ind(k,0);
        for(int i=0;i<k;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<k;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans += 97+curr;
            for(auto it : adj[curr]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        // cout<<ans<<"\n";
        return ans;
    }
};

int main(){
    string dict[] = {"baa","abcd","abca","cab","cad"};
    Solution sol;
    string ans = sol.findOrder(dict,5,4);
    cout<<ans<<"\n";
    string dict2[] = {"caa","aaa","aab"};
    ans = sol.findOrder(dict2,3,3);
    cout<<ans<<"\n";
}
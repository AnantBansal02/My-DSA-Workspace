#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<string>> ans;
    unordered_map<string,int> mp;
    string b;
    void dfs(string curr, vector<string>& seq){
        if(curr == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int level = mp[curr];
        for(int i=0;i<curr.size();i++){
            char ori = curr[i];
            for(char ch='a';ch<='z';ch++){
                curr[i] = ch;
                if(mp.find(curr)!=mp.end() and mp[curr] + 1 == level){
                    seq.push_back(curr);
                    dfs(curr,seq);
                    seq.pop_back();
                }
            }
            curr[i] = ori;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        int level = 0;
        mp[beginWord] = level;
        int sz = beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            int n = q.size();
            level++;
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr==endWord){
                    mp[curr] = level;
                    break;
                }
                for(int i=0;i<sz;i++){
                    char ori = curr[i];
                    for(char it='a';it<='z';it++){
                        curr[i] = it;
                        if(st.find(curr)!=st.end()){
                            q.push(curr);
                            mp[curr] = level;
                            st.erase(curr);
                        }
                    }
                    curr[i] = ori;
                }
            }
            if(st.find(endWord)==st.end()){
                break;
            }
        }
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> arr = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans = sol.findLadders("hit", "cog", arr);
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<"->";
        }cout<<"\n";
    }
}
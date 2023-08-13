#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        while(!q.empty()){
            string curr = q.front().first;
            int seq = q.front().second;
            if(curr == targetWord){
                return seq;
            }
            q.pop();
            for(int i=0;i<curr.size();i++){
                char original = curr[i];
                for(char j = 'a';j <= 'z'; j++){
                    curr[i] = j;
                    if(s.find(curr) != s.end()){
                        q.push({curr,seq+1});
                        s.erase(curr);
                    }
                }
                curr[i] = original;
            }
        }
        return 0;
    }
};

int main(){
    vector<string> arr = {"des","der","dfr","dgt","dfs"};
    string st = "der";
    string tar = "dfs";
    Solution sol;
    cout<<sol.wordLadderLength(st,tar,arr)<<"\n";
}
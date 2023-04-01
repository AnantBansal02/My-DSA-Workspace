/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include<bits/stdc++.h>
using namespace std;

class Trie {

public:
    struct Node{
        Node *links[26];
        bool flag = false;
        bool containskey(char ch){
            return links[ch-'a'] != NULL;
        }
        void setkey(char ch,Node *node){
            links[ch-'a'] = node;
        }
        Node *next(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };

    /** Initialize your data structure here. */
    Node *root = new Node();
    Trie() {
        
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                node->setkey(word[i], new Node());
            }
            node = node->next(word[i]);
        }
        node->setEnd();
    }   

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        Node *node = root;
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->next(word[i]);
        }
        if(node->isEnd()){
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        Node * node = root;
        for(int i=0;i<n;i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node = node->next(prefix[i]);
        }
        return true;
    }
};
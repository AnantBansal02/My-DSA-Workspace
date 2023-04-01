#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class WordDictionary {
public:
    struct Node{
        Node *links[26];
        bool flag = false;
        bool containskey(char ch){
            return links[ch-'a'] != NULL;
        }
        void set(char ch, Node* node){
            links[ch - 'a']  = node;
        }
        Node *next(char ch){
            return links[ch - 'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };
    Node * root = new Node();
    WordDictionary() {
        
    }
    void addWord(string word) {
        int n = word.length();
        Node * node = root;
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                node->set(word[i],new Node());
            }
            node = node->next(word[i]);
        }
        node->setEnd();
    }
    bool mysearch(string word, int i, Node* node) {
        if(i==word.length()){
            return node->isEnd();
        }
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(node->containskey(97+j) and mysearch(word,i+1,node->next(97+j))){
                    return true;
                }
            }
            return false;
        }
        else if(!node->containskey(word[i])){
            return false;
        }
        return mysearch(word,i+1,node->next(word[i]));
    }
    bool search(string word){
        return mysearch(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
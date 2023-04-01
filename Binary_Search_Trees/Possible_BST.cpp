#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node*> Construct_Trees(int start, int end){
    vector<Node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i = start; i <= end; i++){
        vector<Node*> leftSubtrees = Construct_Trees(start, i-1);
        vector<Node*> rightSubtrees = Construct_Trees(i+1, end);
        for(int j=0;j<leftSubtrees.size();j++){
            Node* left = leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void Preorder(Node* root){
    if(root ==  NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
    vector<Node*> trees = Construct_Trees(1,5);
    for(int i=0;i<trees.size();i++){
        cout<< i+1 << " : ";
        Preorder(trees[i]);
        cout<<endl;
    }
    return 0;
}
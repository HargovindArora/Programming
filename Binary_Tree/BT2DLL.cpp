#include<iostream>
#include<vector>
using namespace std;

class TreeNode{

    public:
        TreeNode *left;
        TreeNode *right;
        int data;

        TreeNode(int x): data(x), left(NULL), right(NULL) {}
};

class Solution {

    TreeNode *prev;
    TreeNode *head;

    void b2ll(TreeNode *root){

        if(root==NULL){
            return;
        }
        b2ll(root->left);
        if(prev==NULL){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        b2ll(root->right);

    }

};

int main(int argc, char const *argv[]){



    return 0;
}
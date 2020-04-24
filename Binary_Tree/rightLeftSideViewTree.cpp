#include<iostream>
#include<vector>
using namespace std;

class TreeNode{

    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode *createTreeFromTraversal(int *ino, int *pre, int beg, int end){

    static int i=0;
    if(beg>end){
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[i]);
    int index = -1;
    for(int j=beg; j<=end; j++){
        if(ino[j]==pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(ino, pre, beg, index-1);
    root->right = createTreeFromTraversal(ino, pre, index+1, end);
    return root;
}

class Solution {

    public:
        vector<int> v;
        int max_level_right = -1;
        int max_level_left = -1;

        void traverseRight(TreeNode *root, int level){

            if(root==NULL){
                return;
            }
            if(level>max_level_right){
                max_level_right = level;
                v.push_back(root->val);
            }
            traverseRight(root->right, level+1);
            traverseRight(root->left, level+1);

        }

        void traverseLeft(TreeNode *root, int level){

            if(root==NULL){
                return;
            }
            if(level>max_level_left){
                max_level_left = level;
                v.push_back(root->val);
            }
            traverseLeft(root->left, level+1);
            traverseLeft(root->right, level+1);

        }

        vector<int> rightSideView(TreeNode *root){
            traverseRight(root, 0);
            return v;
        }

        vector<int> leftSideView(TreeNode *root){
            traverseLeft(root, 0);
            return v;
        }

};

int main(int argc, char const *argv[]){

    int ino[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(ino)/sizeof(int);
    TreeNode *root = createTreeFromTraversal(ino, pre, 0, n-1);
    Solution X;
    vector<int> v = X.rightSideView(root);
    for(auto x:v){
        cout << x << " ";
    }
    cout << endl;
    Solution Y;
    vector<int> w = Y.leftSideView(root);
    for(auto x:w){
        cout << x << " ";
    }
    cout << endl;

}
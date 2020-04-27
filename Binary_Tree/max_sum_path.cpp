#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class TreeNode{

    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode (int data): val(data), left(NULL), right(NULL){}
};

class Solution{

    public:
        int globalMax = INT_MIN;
        int maxPathNode2Node(TreeNode *root){

            if(root==NULL){
                return 0;
            }
            int lst = maxPathNode2Node(root->left);
            int rst = maxPathNode2Node(root->right);

            int c1 = root->val;
            int c2 = root->val + lst;
            int c3 = root->val + rst;
            int c4 = lst + root->val + rst;
            globalMax = max(c1, max(c2, max(c3, max(c4, globalMax))));
            return max(lst, max(rst, 0)) + root->val;

        }

};

TreeNode *buildBalancedTree(int *a, int beg, int end){

    if(beg>end){
        return NULL;
    }
    int mid = (beg+end)/2;
    TreeNode *root = new TreeNode(a[mid]);
    root->left = buildBalancedTree(a, beg, mid-1);
    root->right = buildBalancedTree(a, mid+1, end);

    return root;
}

void bst(TreeNode *root){

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        TreeNode *val = q.front();
        if(val==NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout << val->val << " ";
        q.pop();
        if(val->left){
            q.push(val->left);
        }
        if(val->right){
            q.push(val->right);
        }

    }
    return;
}

int main(int argc, char const *argv[]){

    int a[] = {4,2,5,1,3,6,7};
    int n = sizeof(a)/sizeof(int);
    TreeNode *root = buildBalancedTree(a, 0, n-1);
    bst(root);
    Solution X;
    X.maxPathNode2Node(root);
    cout << X.globalMax << endl;

    return 0;
}

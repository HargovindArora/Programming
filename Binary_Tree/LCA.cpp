#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{

    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Custom{

    public:
        bool hasKey1;
        bool hasKey2;
        TreeNode *node;
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

Custom *helper(TreeNode *root, TreeNode *p, TreeNode *q){

    if(root==NULL){
        return NULL;
    }
    Custom *leftans = helper(root->left, p, q);
    if(leftans!=NULL and leftans->node!=NULL){
        return leftans;
    }
    Custom *rightans = helper(root->right, p, q);
    if(rightans!=NULL and rightans->node!=NULL){
        return rightans;
    }
    Custom *result = new Custom();
    if(leftans!=NULL and rightans!=NULL){
        result->node = root;
        result->hasKey1 = true;
        result->hasKey2 = true;
        return result;
    }
    else if(root->val = p->val){
        result->hasKey1 = true;
        result->hasKey2 = (leftans)?leftans->hasKey2:false or (rightans)?rightans->hasKey2:false;
        if(result->hasKey1 and result->hasKey2){
            result->node = root;
        }
        return result;
    }
    else if(root->val = q->val){
        result->hasKey2 = true;
        result->hasKey1 = (leftans)?leftans->hasKey1:false or (rightans)?rightans->hasKey1:false;
        if(result->hasKey1 and result->hasKey2){
            result->node = root;
        }
        return result;
    }
    else if(leftans){
        return leftans;
    }
    else if(rightans){
        return rightans;
    }
    return NULL;

}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){

    Custom *result = helper(root, p, q);
    if(result==NULL){
        return NULL;
    }
    else{
        return result->node;
    }

}

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

void breadthFirstSearch(TreeNode *root){

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

    int ino[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int n = sizeof(ino)/sizeof(int);
    TreeNode *root = buildBalancedTree(ino, 0, n-1);
    breadthFirstSearch(root);
    TreeNode *x = lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << x->val << endl;
    return 0;
}
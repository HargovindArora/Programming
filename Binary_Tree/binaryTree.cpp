#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node (int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node *buildTree(){
    int d;
    cin >> d;

    if(d==-1){
        return NULL;
    }
    
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(node *root){

    if(root==NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

void inOrder(node *root){

    if(root==NULL){
        return;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

void postOrder(node *root){

    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

}

int height(node *root){

    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs)+1;

}

void printKthLevel(node *root, int k){

    if(root==NULL){
        return;
    }
    if(k==1){
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void levelOrderRecursive(node *root){

    int H = height(root);

    for(int i=1; i<=H; i++){
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

void breadthFirstSearch(node *root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *val = q.front();
        if(val==NULL){
            cout << endl; // New Level
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout << val->data << " ";
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

int countNodes(node *root){
    
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);

}

int sumOfNodes(node *root){

    if(root==NULL){
        return 0;
    }
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);

}

int diameterOfTree(node *root){

    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameterOfTree(root->left);
    int op3 = diameterOfTree(root->right);
    return max(op1, max(op2, op3));
}

class Pair{

    public:
        int height;
        int diameter;
};

Pair fastDiameter(node *root){ // Post Order Traversal - Bottom Up

    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
    return p;

}

int replaceSum(node *root){

    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);
    int temp = root->data;
    root->data = leftSum+rightSum;
    return temp+root->data;

}

class HBPair{

    public:
        int height;
        bool balance;
};

HBPair isHeightBalance(node *root){

    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);
    p.height = max(left.height, right.height)+1;
    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

node *buildBalancedTree(int *a, int beg, int end){

    if(beg>end){
        return NULL;
    }
    int mid = (beg+end)/2;
    node *root = new node(a[mid]);
    root->left = buildBalancedTree(a, beg, mid-1);
    root->right = buildBalancedTree(a, mid+1, end);

    return root;
}

node *createTreeFromTraversal(int *ino, int *pre, int beg, int end){

    static int i=0;
    if(beg>end){
        return NULL;
    }
    node *root = new node(pre[i]);
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

class Pair2{
    public:
        int branchSum;
        int maxSum;

        Pair2(){
            branchSum = 0;
            maxSum = 0;
        }
};

Pair2 maxSumPath(node *root){

    Pair2 p;
    if(root == NULL){
        return p;
    }

    Pair2 left = maxSumPath(root->left);
    Pair2 right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = left.branchSum + root->data + right.branchSum; 

    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));
    return p;
}

node *lca(node *root, int a, int b){

    if(root==NULL){
        return NULL;
    }
    if(root->data==a or root->data==b){
        return root;
    }

    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if(leftans!=NULL and rightans!=NULL){
        return root;
    }

    if(leftans!=NULL){
        return leftans;
    }
    return rightans;
}

int main(){

    // node *root = buildTree();
    // preOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;

    // printKthLevel(root, 2);
    // breadthFirstSearch(root);
    // cout << sumOfNodes(root) << endl;
    // cout << countNodes(root) << endl;
    // cout << diameterOfTree(root) << endl;

    // Pair p = fastDiameter(root);
    // cout << p.diameter << endl;
    // cout << p.height << endl;
    // replaceSum(root);
    // cout << endl;
    
    // int a[] = {1, 2, 3, 4, 5, 6, 7};

    // node *root = buildBalancedTree(a, 0, 6);
    // breadthFirstSearch(root);
    // if(isHeightBalance(root).balance){
    //     cout << "It is a balanced tree\n";
    // }
    // else{
    //     cout << "Not a balanced tree\n";
    // }

    int ino[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(ino)/sizeof(int);
    node *root = createTreeFromTraversal(ino, pre, 0, n-1);
    breadthFirstSearch(root);

    return 0;
}
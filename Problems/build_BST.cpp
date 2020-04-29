#include<iostream>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node *buildBalancedBST(int *a, int beg, int end){

    if(beg>end){
        return NULL;
    }
    int mid = (beg+end)/2;
    node *root = new node(a[mid]);
    root->left = buildBalancedBST(a, beg, mid-1);
    root->right = buildBalancedBST(a, mid+1, end);

    return root;
}

void preorder(node *root){

    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        node *root = buildBalancedBST(a, 0, n-1);
        preorder(root);

    }
    
    return 0;
}
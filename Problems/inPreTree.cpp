#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int d) : data(d), left(NULL), right(NULL){}
};

node *treeFromTraversal(int *ino, int *pre, int beg, int end){

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
    root->left = treeFromTraversal(ino, pre, beg, index-1);
    root->right = treeFromTraversal(ino, pre, index+1, end);
    return root;
}

void preOrder(node *root){

    if(root==NULL){
        return;
    }

    if(root->left==NULL){
        cout << "END => ";
    }
    else{
        cout << root->left->data << " => ";
    }
    cout << root->data << " ";
    if(root->right==NULL){
        cout << "<= END" << endl;
    }
    else{
        cout << "<= " << root->right->data << endl;
    }

    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    int n;
    cin >> n;
    int pre[n];
    for(int i=0; i<n; i++){
        cin >> pre[i];
    }
    int m;
    cin >> m;
    int ino[m];
    for(int i=0; i<n; i++){
        cin >> ino[i];
    }
    node *root = treeFromTraversal(ino, pre, 0, n-1);
    preOrder(root);

    return 0;
}
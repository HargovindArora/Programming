#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int d) : data(d), left(NULL), right(NULL) {}
};

node *insertInBST(node *root, int x){

    if(root==NULL){
        return new node(x);
    }
    if(x<=root->data){
        root->left = insertInBST(root->left, x);
    }
    else{
        root->right = insertInBST(root->right, x);
    }
    return root;
}

node *buildBST(int *a, int n){

    node *root = NULL;
    int i=0;
    while(i<n){

        root =  insertInBST(root, a[i]);
        i++;
    }

    return root;
}

node *deleteInBST(node *root, int data){

    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if(data==root->data){
        
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL and root->right==NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL and root->right!=NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        node *replace = root->right;
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteInBST(root->right, data);
        return root;
    }

}

void preOrder(node *root){

    if(root==NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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
        node *root = buildBST(a, n);
        int m;
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            root = deleteInBST(root, x);
        }
        preOrder(root);
    }

    return 0;
}
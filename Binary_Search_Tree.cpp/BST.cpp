#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node *insertInBst(node *root, int data){

    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left = insertInBst(root->left, data);
    }
    else{
        root->right = insertInBst(root->right, data);
    }
    return root;
}

node *build(){

    int d;
    cin >> d;

    node *root = NULL;

    while(d!=-1){

        root = insertInBst(root, d);
        cin >> d;

    }
    return root;
}

void breadthFirstSearch(node *root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *val = q.front();
        if(val==NULL){
            cout << endl;
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

void inorder(node *root){

    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    node *root = build();
    breadthFirstSearch(root);
    inorder(root);

    return 0;
}
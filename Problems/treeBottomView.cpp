#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        int hd;
        node *left;
        node *right;

        node(int d){
            data = d;
            hd = INT_MAX;
            left = NULL;
            right = NULL;
        }
};

void bottomViewOfTree(node *root){

    if(root==NULL){
        return;
    }
    int hd = 0;
    map<int, int> m;
    queue<node*> q;
    root->hd = hd;
    q.push(root);
    while(!q.empty()){

        node *temp = q.front();
        q.pop();
        hd = temp->hd;
        m[hd] = temp->data;
        if(temp->left!=NULL){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }

    }

    for(auto i=m.begin(); i!=m.end(); i++){
        cout << i->second << " ";
    }
    return;
}

// node *buildLevelOrder(node *&root, int x, queue<node*> &q){

//     node *temp = new node(x);
//     if(root==NULL){
//         root = temp;
//     }
//     else if(q.front()->left==NULL){
//         q.front()->left = temp;
//     }
//     else {
//         q.front()->right = temp;
//         q.pop();
//     }
//     q.push(temp);
//     return root;
// }

node *buildTree(){

    queue<node*> q;
    int n;
    cin >> n;
    
    if(n==-1){
        return NULL;
    }
    node *root = new node(n);
    q.push(root);
    while(!q.empty()){

        node *temp = q.front();
        q.pop();
        cin >> n;
        if(n==-1){
            cin >> n;
        }
        else{
            temp->left = new node(n);
            q.push(temp->left);
            cin >> n;
        }
        if(n==-1){
            continue;
        }
        temp->right = new node(n);
        q.push(temp->right);
    }
    

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

int main(){

    node *root = buildTree();
    // preOrder(root);
    bottomViewOfTree(root);

    return 0;
}
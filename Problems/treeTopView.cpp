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

void treeTopView(node *root){

    if(root==NULL){
        return;
    }
    queue<node*> q;
    map<int, int> m;
    int hd=0;
    root->hd = hd;
    q.push(root);
    while(!q.empty()){

        hd = root->hd;
        if(m.count(hd)==0){
            m[hd] = root->data;
        }
        if(root->left!=NULL){
            root->left->hd = hd-1;
            q.push(root->left);
        }
        if(root->right!=NULL){
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();

    }

    for(auto i=m.begin(); i!=m.end(); i++){
        cout << i->second << " ";
    }
    cout << endl;

}

int main(){

    node *root = buildTree();
    treeTopView(root);

    return 0;
}
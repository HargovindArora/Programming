#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;
        node(int d) : data(d), left(NULL), right(NULL){}
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

vector<int> v;
int max_level_right = -1;
void traverseRight(node *root, int level){

    if(root==NULL){
        return;
    }
    if(level>max_level_right){
        max_level_right = level;
        v.push_back(root->data);
    }
    traverseRight(root->right, level+1);
    traverseRight(root->left, level+1);
    return;
}

int main(){

    node *root = buildTree();
    traverseRight(root, 0);
    for(auto x:v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
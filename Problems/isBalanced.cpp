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

    int x;
    cin >> x;
    node *root = new node(x);

    string left;
    cin >> left;
    if(left=="true"){
        root->left = buildTree();
    }

    string right;
    cin >> right;
    if(right=="true"){
        root->right = buildTree();
    }

    return root;
}

class HBPair{

    public:
        int height;
        bool balance;
};

HBPair isHeightBalanced(node *root){

    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    //BottomUp Approach
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    //Self Work
    p.height = max(left.height, right.height)+1;
    if(abs(left.height-right.height)<=1 and left.balance and right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

int main(){

    node *root = NULL;
    root = buildTree();
    HBPair p;
    if(isHeightBalanced(root).balance){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}
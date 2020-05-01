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

bool areTreesStructurallyIdentical(node *root1, node *root2) {
    if(root1==NULL and root2==NULL) {
        return true;
    }
    if(root1!=NULL and root2!=NULL) {
        int leftAns = areTreesStructurallyIdentical(root1->left, root2->left);
        int rightAns = areTreesStructurallyIdentical(root1->right, root2->right);
        return leftAns and rightAns;
    }
    return false;
}

int main(){

    node *root1 = buildTree();
    node *root2 = buildTree();

    if(areTreesStructurallyIdentical(root1, root2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}
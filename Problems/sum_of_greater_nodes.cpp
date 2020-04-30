#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left = NULL;
        node *right = NULL;

        node(int d) : data(d), left(NULL), right(NULL) {}
};

node *buildbalancedTree(int *ino, int beg, int end){

    if(beg>end){
        return NULL;
    }
    int mid = (beg+end)/2;
    node *root = new node(ino[mid]);
    root->left = buildbalancedTree(ino, beg, mid-1);
    root->right = buildbalancedTree(ino, mid+1, end);
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

    int n;
    cin >> n;
    int ino[n];
    for(int i=0; i<n; i++){
        cin >> ino[i];
    }
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += ino[j];
        }
        ino[i] = sum;
    }
    node *root = buildbalancedTree(ino, 0, n-1);
    preOrder(root);

    return 0;
}
#include<bits/stdc++.h>
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

node *buildBST(node *root, int data){

    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left = buildBST(root->left, data);
    }
    else{
        root->right = buildBST(root->right, data);
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
    return;
}

void Print(node *root, int k1, int k2)
{
/* base case */
if ( NULL == root )
    return;

/* Since the desired o/p is sorted, recurse for left subtree first
    If root->data is greater than k1, then only we can get o/p keys
    in left subtree */
if ( k1 < root->data )
    Print(root->left, k1, k2);

/* if root's data lies in range, then prints root's data */
if ( k1 <= root->data && k2 >= root->data )
    printf("%d ", root->data );

/* If root->data is smaller than k2, then only we can get o/p keys
    in right subtree */
if ( k2 > root->data )
    Print(root->right, k1, k2);
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int a[n];
        node *root = NULL;
        for(int i=0; i<n; i++){
            cin >> a[i];
            root = buildBST(root, a[i]);
        }
        cout << "# Preorder : ";
        preOrder(root);
        cout << endl;
        sort(a, a+n);
        int k1, k2;
        cin >> k1 >> k2;
        cout << "# Nodes within range are : ";
        for(int i=0; i<n; i++){
            if(a[i]>=k1 and a[i]<=k2){
                cout << a[i] << " ";
            }
        }
        cout << endl;

    }

    return 0;
}
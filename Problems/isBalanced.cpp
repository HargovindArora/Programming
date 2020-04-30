#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int d) : data(d), left(NULL), right(NULL){}
};

// node *buildTree(node *root){

//     int x;
//     cin >> x;
//     root = new node(x);
//     bool b;
//     cin >> b;
    
//     if(b==false){
//         root->left = NULL;
//         cin >> b;
//         if(b==false){
//             root->right = NULL;
//         }
//         else{
//             root->right = buildTree(root->right);
//         }
//     }
//     else{
//         root->left = buildTree(root->left);
//         cin >> b;
//         if(b==false){
//             root->right = NULL;
//         }
//         else{
//             root->right = buildTree(root->right);
//         }
//     }
//     return root;
// }

node * buildTree()
{
int cdata;
cin>>cdata;
node * root= new node(cdata);

		// left
		string hlc;
        cin>>hlc;

		if (hlc=="true") {
			root->left = buildTree();
		}

		// right
        string hrc;
        cin>>hrc;

		if (hrc=="true") {
			root->right = buildTree();
		}

		// return
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

    node *root = NULL;
    root = buildTree();
    preOrder(root);

    return 0;
}
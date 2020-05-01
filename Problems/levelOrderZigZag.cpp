#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;

        node(int d) : data(d), left(NULL), right(NULL) {}
};

node *buiildTree(){

    int x;
    cin >> x;
    node *root = new node(x);

    string left;
    cin >> left;
    if(left=="true"){
        root->left = buiildTree();
    }

    string right;
    cin >> right;
    if(right=="true"){
        root->right = buiildTree();
    }

    return root;
}

void traverseZigZag(node *root){

    if(root==NULL){
        return;
    }

    stack<node*> currLevel;
    stack<node*> nextLevel;

    currLevel.push(root);
    bool leftToRight = true;

    while(!currLevel.empty()){

        node *temp = currLevel.top();
        currLevel.pop();

        if(temp){

            cout << temp->data << " ";

            if(leftToRight){
                if(temp->left!=NULL){
                    nextLevel.push(temp->left);
                }
                if(temp->right!=NULL){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if(temp->right!=NULL){
                    nextLevel.push(temp->right);
                }
                if(temp->left!=NULL){
                    nextLevel.push(temp->left);
                }
            }

        }

        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }

    }

}

int main(){

    node *root = buiildTree();
    traverseZigZag(root);

    return 0;
}